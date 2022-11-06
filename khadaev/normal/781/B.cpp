#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<string, string>> a(n);
    forn(i, 0, n) {
        string s1, s2;
        cin >> s1 >> s2;
        string t1 = s1.substr(0, 3),  t2 = s1.substr(0, 2) + s2.substr(0, 1);
        a[i] = {t1, t2};
    }
    map<string, int> cnt, cnt2;
    forn(i, 0, n) cnt[a[i].fs]++;
    vector<string> ans(n, "");
    forn(i, 0, n) {
        if (cnt[a[i].fs] > 1) {
            ans[i] = a[i].sn;
            cnt2[a[i].sn]++;
        }
    }
    while (1) {
        bool fnd = false;
        forn(i, 0, n) {
            if (!ans[i].empty()) continue;
            auto it = cnt2.find(a[i].fs) ;
            if (it != cnt2.end()) {
                ans[i] = a[i].sn;
                cnt2[a[i].sn]++;
                fnd = true;
            }
        }
        if (!fnd) break;
    }
    forn(i, 0, n) if (ans[i].empty()) ans[i] = a[i].fs;
    forn(i, 0, n) forn(j, 0, i) if (ans[i] == ans[j]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    forn(i, 0, n) cout << ans[i] << '\n';
}