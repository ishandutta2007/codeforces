#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    map<char, int> mp;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        mp[s[i]]--;
    }
    for(auto p: mp){
        if(p.second != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}