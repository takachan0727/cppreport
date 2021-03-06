/* sample 3 */
#include <iostream>
using namespace std;

class person{
public:
  string address;
  string name;
};

class addressbook{
  friends = new person [100];
  int numberOfFriends;
  ~addressbook;
public:
  addressbook();
  void listFriends();
  void addFriend(string n, string a);
  person find(string query);
};

// constructor
addressbook::addressbook(){
  numberOfFriends = 0;
}

~addressbook{
  delete[] friends;
}
void addressbook::addFriend(string n, string a){
  friends[numberOfFriends].name = n;
  friends[numberOfFriends].address = a;
  numberOfFriends++;
}

void addressbook::listFriends(){
  for(int i = 0; i < numberOfFriends; i++){
    cout << friends[i].name << ":" << friends[i].address << "\n";
  }
}

person addressbook::find(string query){
  for(int i = 0; i < numberOfFriends; i++){
    if(friends[i].name == query){
        return friends[i];
    }
  }
  person no_one;
  no_one.name = "";
  return no_one;
}

int main()
{
  addressbook abook;
  string name;
  string address;

  string query;
  person found;


  while(1){
    cout << "住所録に登録する名前を入力してください（終了するにはquitと入力してください）: ";
    cin >> name;
    //   cout << "name.length() = " << name.length() << "\n";
    if(name == "quit"){break;}
    cout << "住所録に登録する住所を入力してください（終了するにはquitと入力してください）: ";
    cin >> address;
    abook.addFriend(name, address);
    }

    cout << "探したい名前を入力してください";
    cin >> query;
    found = abook.find(query);
    if(found.name != ""){
      cout << found.name << ":" << found.address;
    }else{
      cout << "見つかりませんでした。";
    }

  cout << "\n名前リスト:\n";
  abook.listFriends();
}
