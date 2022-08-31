//Codeforces Round #395 Div1E solution
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cassert>
#include <tuple>
#include <list>
#include <iterator>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define forn(i, n) for (int i = 0; i < ((int)(n)); ++i)
#define forrn(i, s, n) for (int i = (int)(s); i < ((int)(n)); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()


const int INF = 1791791791;
const ll INFLL = 1791791791791791791ll;

class dsu {
    vector<int> par;
    vector<int> rank;
public:
    int cnum;
    dsu() {}
    dsu(int n) {
        cnum = n;
        par.resize(n);
        iota(all(par), 0);
        rank.resize(n, 1);
    }
    int get(int u) {
        if (u != par[u])
            par[u] = get(par[u]);
        return par[u];
    }
    void merge(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        cnum--;
        if (rank[u] > rank[v])
            swap(u, v);
        par[u] = v;
        rank[v] = max(rank[v], rank[u] + 1);
    }
};

class solve {
    int n, k;
    vector<vector<int> > graph;
    vector<dsu> tree;
    void build(int v, int L, int R) {
        tree[v] = dsu(R - L);
        forrn(i, L, R) {
            for (int u : graph[i]) {
                if (L <= u && u < R)
                    tree[v].merge(i - L, u - L);
            }
        }
        if (L != R - 1) {
            build(2 * v + 1, L, (L + R) >> 1);
            build(2 * v + 2, (L + R) >> 1, R);
        }
    }
    vector<tuple<int, int, int> > vertex;
    void get_vertex(int v, int L, int R, int l, int r) {
        if (r <= L || R <= l)
            return;
        else if (l <= L && R <= r)
            vertex.pb(mt(v, L, R));
        else {
            get_vertex(2 * v + 1, L, (L + R) >> 1, l, r);
            get_vertex(2 * v + 2, (L + R) >> 1, R, l, r);
        }
    }
    int different(vector<int> vec) {
        sort(all(vec));
        return distance(vec.begin(), unique(all(vec)));
    }
    int on_two_segments(vector<int> fvec, int fl, int fr, vector<int> svec, int sl, int sr) {
        assert(fr == sl);

        vector<int> fcds = fvec;
        sort(all(fcds));
        fcds.resize(distance(fcds.begin(), unique(all(fcds))));
        vector<int> scds = svec;
        sort(all(scds));
        scds.resize(distance(scds.begin(), unique(all(scds))));
        int m = fcds.size();
        
        dsu ds(fcds.size() + scds.size());
        forrn(i, fl, fr) {
            for (int u : graph[i])
                if (sl <= u && u < sr)
                    ds.merge(lb(all(fcds), fvec[i - fl]) - fcds.begin(), m + (lb(all(scds), svec[u - sl]) - scds.begin()));
        }
        
        return ds.cnum;
    }
    vector<int> segment_comps(int l, int r) {
        vector<int> ans;
        dsu ds(r - l);
        forrn(i, l, r) {
            for (int u : graph[i])
                if (l <= u && u < r)
                    ds.merge(i - l, u - l);
        }
        forrn(i, l, r)
            ans.pb(ds.get(i - l));
        return ans;
    }
public:
    solve(int _n, int _k) {
        n = _n; k = _k;
        graph.resize(n);
        tree.resize(4 * n);
    }
    void add_edge(int u, int v) {
        graph[u].pb(v);
        graph[v].pb(u);
    }
    void precalc() {
        build(0, 0, n);
    }
    int compnum(int l, int r) {
        vertex.clear();
        get_vertex(0, 0, n, l, r);
        int cur = 0;
        vector<int> last;
        int cl = l, cr = l;
        for (auto t : vertex) {
            int v = get<0>(t);
            int L = get<1>(t);
            assert(L == cr);
            int R = get<2>(t);

            int sl = max(cr - k, cl);
            int sr = min(L + k, R);

            int n1 = different(last);
            vector<int> next;
            forrn(i, L, sr)
                next.pb(tree[v].get(i - L));
            int n2 = different(next);

            cur = cur + tree[v].cnum - (n1 + n2) + on_two_segments(last, sl, cr, next, L, sr);
            cr = R;
            if (R - L >= k) {
                last.clear();
                forrn(i, R - k, R)
                    last.pb(tree[v].get(i - L));
            } else
                last = segment_comps(max(cl, cr - k), cr);
        }
        return cur;
    }
};

int main() {
    // Code here:
   
    int n, k;
    scanf("%d %d", &n, &k);
    solve prob(n, k);
    int m;
    scanf("%d", &m);
    forn(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        prob.add_edge(u, v);
    }
    prob.precalc();
    int q;
    scanf("%d", &q);
    forn(i, q) {
        
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        printf("%d\n", prob.compnum(l, r));
    }

    return 0;
}