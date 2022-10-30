#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC optimize("unroll-loops")
using namespace std;

#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef list<int> vi;

//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 3e5 + 22;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = (ll) 1e18 + 5;
const int inf = 2e9 + 5;

bool us[maxn];

struct Dsu
{
    vector<int> parent, _rank, sum;

    int comp, n;

    void make_set(int v) {
        parent[v] = v;
        _rank[v] = 0;
        sum[v] = us[v];
    }

    Dsu() {}
    Dsu(int _n) {
        n = _n;
        comp =  n;

        parent.resize(n);
        _rank.resize(n);
        sum.resize(n);

        for (int i = 0; i < n; i++)
            make_set(i);
    }

    int find_set (int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets (int a, int b) {
        a = find_set (a);
        b = find_set (b);
        if (a != b) {
            if (_rank[a] < _rank[b])
                swap (a, b);
            parent[b] = a;
            sum[a] += sum[b];
            if (_rank[a] == _rank[b])
                ++_rank[a];
        }
    }
};


int main() {
    // freopen("input.txt", "r", stdin);

    int n, m, k;
    cin >> n >> m >> k;


    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        us[x] = 1;
    }

    Dsu dsu(n);

    vector<pair<int, pii> > e;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        e.pb(mp(w,mp(u, v)));
    }
    sort(all(e));

    int ans = 0;
    for (auto a : e) {
        int u = a.s.f, v = a.s.s, w = a.f;
        if (dsu.find_set(u) != dsu.find_set(v)) {
            if (dsu.sum[dsu.find_set(u)] && dsu.sum[dsu.find_set(v)]) {
                ans = max(ans, w);
            }
            dsu.union_sets(u, v);
        }
    }

    for (int i = 0; i < k; i++)
        cout << ans << ' ';
    return 0;
}