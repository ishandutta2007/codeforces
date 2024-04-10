#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
 
using namespace std;

const int n = 2e5 + 1;
bitset<n> f[26], ans;
int p[26];
string s, t;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 26; i++) cin >> p[i];
    cin >> s >> t;
    ans.set();
    for (int i = 0; i < t.size(); i++) {
        f[t[i] - 'a'][i] = 1;
    }
    for (int i = 0; i < s.size(); i++) ans = ans & (f[s[i] - 'a'] | f[p[s[i] - 'a'] - 1]) >> i;
    for (int i = 0; i <= t.size() - s.size(); i++) cout << ans[i];
}