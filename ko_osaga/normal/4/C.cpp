#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,int> mp;

int main(){
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if(mp.find(s) == mp.end()){
            cout << "OK" << endl;
        }
        else{
            cout << s << mp[s] << endl;
        }
        mp[s]++;
    }
}