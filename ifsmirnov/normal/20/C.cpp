#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 100500;
const i64 inf = 1e18;
vector<pair<int, i64>> e[maxn];
int n, m;

void scan() {
    cin >> n >> m;
    forn(i, m) {
        int u, v;
        int w;
        cin >> u >> v >> w;
        --u, --v;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
}

i64 d[maxn];
int b[maxn];
int anc[maxn];

void dijkstra() {
    using WP = pair<i64, int>;
    int S = 0;

    forn(i, n) d[i] = inf, b[i] = 0;
    priority_queue<WP, vector<WP>, greater<WP>> q;
    d[S] = 0;
    q.emplace(d[S], S);

    while (!q.empty()) {
        int v = q.top().second;
        q.pop();

        if (b[v]) continue;
        b[v] = 1;

        for (auto kv: e[v]) {
            int to, w;
            tie(to, w) = kv;
            if (d[to] > d[v] + w) {
                d[to] = d[v] + w;
                anc[to] = v;
                q.emplace(d[to], to);
            }
        }
    }
}

void solve() {
    dijkstra();
    if (d[n-1] == inf) {
        cout << -1 << endl;
    } else {
        vi res;
        for (int v = n-1; v != 0; v = anc[v]) {
            res.push_back(v);
        }
        res.push_back(0);
        reverse(all(res));
        for (int x: res) cout << x+1 << " ";
        cout << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}