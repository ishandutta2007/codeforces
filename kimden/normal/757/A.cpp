#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;

int main(){
    string s;
    cin >> s;
    map<char, int> mp;
    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }
    int ans = 0;
    ans = min(mp['B'], mp['l']);
    ans = min(ans, mp['b']);
    ans = min(ans, mp['s']);
    ans = min(ans, mp['u']/2);
    ans = min(ans, mp['r']);
    ans = min(ans, mp['a']/2);
    cout << ans << endl;
    return 0;
}