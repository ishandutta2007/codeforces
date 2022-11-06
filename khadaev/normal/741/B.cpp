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

const int N = 1001;
int u[N], weis[N], b[N], ans[N];
vector<int> e[N];
vector<pair<int, int>> comp;
pair<int, int> sw;

void dfs(int i) {
    if (u[i]) return;
    u[i] = 1;
    comp.eb(weis[i], b[i]);
    sw.first += weis[i];
    sw.second += b[i];
    for (int j : e[i]) dfs(j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, w;
    cin >> n >> m >> w;
    forn(i, 0, n) cin >> weis[i];
    forn(i, 0, n) cin >> b[i];
    forn(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        e[x].eb(y), e[y].eb(x);
    }
    forn(i, 0, n) {
        if (u[i]) continue;
        comp.clear();
        sw = {0, 0};
        dfs(i);
        for (int j = w; j >= 0; --j) {
            for (auto t : comp)
                if (t.first <= j)
                    ans[j] = max(ans[j], ans[j - t.first] + t.second);
            if (sw.first <= j)
                ans[j] = max(ans[j], ans[j - sw.first] + sw.second);
        }
    }
    int Ans = 0;
    fore(i, 0, w) Ans = max(Ans, ans[i]);
    cout << Ans << '\n';

}