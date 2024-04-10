#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    string s, t, u;
    cin >> s;
    cin >> t;
    cin >> u;
    map<char, char> mp;
    for(int i = 0; i < s.length(); ++i){
        mp[s[i]] = t[i];
        mp[s[i] + 'A' - 'a'] = t[i] + 'A' - 'a';
    }
    for(int i = 0; i < 10; ++i){
        mp[(char)('0' + i)] = (char)('0' + i);
    }
    for(int i = 0; i < u.length(); ++i){
        cout << mp[u[i]];
    }
    cout << endl;


    return 0;
}