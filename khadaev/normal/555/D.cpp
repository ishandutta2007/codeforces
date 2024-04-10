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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> x(n);
    forn(i, 0, n) cin >> x[i].fs;
    forn(i, 0, n) x[i].sn = i;
    sort(all(x));
    vector<int> pos(n);
    forn(i, 0, n) pos[x[i].sn] = i;
    while (m--) {
        int a, l;
        cin >> a >> l;
        --a;
        a = pos[a];
        while (l) {
            int pr = a;
            int old_l = l;
            int a1 = upper_bound(all(x), make_pair(x[a].fs + l, INF)) - x.begin() - 1;
            l -= (x[a1].fs - x[a].fs);
            a = a1;
            a1 = lower_bound(all(x), make_pair(x[a].fs - l, -INF)) - x.begin();
            l -= (x[a].fs - x[a1].fs);
            if (l == old_l) break;
            if (a1 == pr)
                l %= (old_l - l);
            a = a1;
        }
        cout << 1 + x[a].sn << '\n';
    }
}