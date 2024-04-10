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

const int N = 1e5 + 10;
const int BOUND = 500;
const int BIG_CNT = 410;

struct Hash {
    size_t operator() (const pair<int, int> &p) const {
        return 1234 * p.fs + p.sn;
    }
};

vector<pair<int, int>> col[N];
map<int, int> dsu;

void add(int i) {
    if (dsu.find(i) == dsu.end())
        dsu[i] = i;
}

int get(int i) {
    if (dsu[i] == i) return i;
    return dsu[i] = get(dsu[i]);
}

void unite(int i, int j) {
    add(i);
    add(j);
    i = get(i);
    j = get(j);
    if (i == j) return;
    dsu[i] = j;
}

vector<int> group[2 * N];
bitset<BIG_CNT> big[N];
unordered_map<pair<int, int>, int, Hash> small;

int main() {
    small.max_load_factor(0.25);
    small.reserve(512);
    int n, m;
    scanf("%d %d", &n, &m);
    forn(i, 0, m) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        col[--c].eb(--a, --b);
    }

    int cnt = 0;
    forn(c, 0, N) {
        for (auto p : col[c])
            unite(p.fs, p.sn);
        map<int, int> id;
        vector<int> vs;
        for (auto p : dsu) vs.eb(p.fs);
        for (int v : vs) {
            int u = get(v);
            auto it = id.find(u);
            int x;
            if (it == id.end()) {
                id[u] = cnt;
                x = cnt++;
            } else x = it->sn;
            group[x].eb(v);
        }
        dsu.clear();
    }


    int cnt_big = 0;
    forn(i, 0, cnt) {
        //for (int j : group[i]) cerr << j << ' ';
        //cerr << '\n';

        if (group[i].size() > BOUND) {
            for (int j : group[i])
                big[j].set(cnt_big);
            ++cnt_big;
        } else {
            for (int j : group[i]) {
                for (int k : group[i]) {
                    if (k == j) break;
                    assert(k < j);
                    ++small[{k, j}];
                }
            }
        }
    }

    int q;
    scanf("%d", &q);
    forn(i, 0, q) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        if (u > v) swap(u, v);
        int ans = (big[u] & big[v]).count();
        auto it = small.find({u, v});
        if (it != small.end()) ans += it->sn;
        printf("%d\n", ans);
    }
}