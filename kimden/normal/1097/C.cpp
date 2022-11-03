#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    map<int, pii> mp;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        int mn = 0, bal = 0;
        for(int j = 0; j < s.length(); ++j) {
            bal += (s[j] == '(' ? 1 : -1);
            mn = min(mn, bal);
        }
        if (bal == 0) {
            if (mn >= 0) {
                ++mp[bal].first;
            }
        }else {
            if (bal > 0) {
                if (mn >= 0)
                    ++mp[bal].first;
            }else {
                if (mn - bal >= 0) {
                    ++mp[-bal].second;
                }
            }
        }
    }
    int ans = 0;
    for(auto u: mp) {
        if(u.first == 0) {
            ans += u.second.first / 2;
        }else{
            ans += min(u.second.first, u.second.second);
        }
    }
    cout << ans << endl;

}