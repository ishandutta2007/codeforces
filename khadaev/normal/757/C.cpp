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
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, int>>> tp(m);
    while (n--) {
        map<int, int> cnt;
        int g;
        scanf("%d", &g);
        while (g--) {
            int x;
            scanf("%d", &x);
            --x;
            cnt[x]++;
        }
        for (auto p : cnt) {
            tp[p.fs].eb(n, p.sn);
        }
    }
    sort(all(tp));
    int cnt = 1;
    ll ans = 1;
    forn(i, 1, m) {
        if (tp[i] == tp[i - 1]) ++cnt;
        else {
            fore(j, 1, cnt) ans = ans * j % MOD;
            cnt = 1;
        }
    }
    fore(j, 1, cnt) ans = ans * j % MOD;
    printf("%lld\n", ans);
}