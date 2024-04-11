#include <iostream>
#include <string>
#include <map>
using namespace std;

string s;
map<string,int> mp;

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s;
        mp[s]++;
    }
    int ret = 0;
    for (auto &i : mp){
        ret = max(ret,i.second);
    }
    cout << ret;
}