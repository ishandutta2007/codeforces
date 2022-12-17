#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define double long double
using namespace std;
const int N = 3e5 + 1;
const int mod = 1e9 + 7;
int pr[N];

set <int> t[26];

void solve() {
    string s;
    int i, j, k, n, m, q, l, r;
    cin >> s;
    cin >> q;
    for (i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1])
            pr[i] = pr[i - 1] + 1;
        else
            pr[i] = pr[i - 1];
        t[s[i] - 'a'].insert(i + 1);
    }
    t[s[0] - 'a'].insert(1);
    for (i = 0; i < q; ++i) {
        cin >> l >> r;
        int cnt = 0;
        for (j = 0; j < 26; ++j)
        if (t[j].lower_bound(l) != t[j].end() && *t[j].lower_bound(l) <= r)
            ++cnt;
        if (l == r || s[r - 1] != s[l - 1] || cnt >= 3)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
        solve();
}