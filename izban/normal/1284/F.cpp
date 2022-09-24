#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif
const int INF = 1e9;

typedef long long ll;
typedef long double ld;

template<typename cap_t, typename excess_t, bool global_relabeling = true, bool min_cut_only = false, bool shuffle_edges = false>
class Push_Relabel{
public:
    struct Edge{
        int to, rev;
        cap_t f, pushed{0};
    };

    Push_Relabel(int n_):n(n_), m(0){}

    void add_edge(int u, int v, cap_t c, cap_t c_rev = 0){
        edge_pool.emplace_back(u, v, c, c_rev);
        ++m;
    }
    excess_t max_flow(int s_, int t_){
        s = s_; t = t_;
        run_pr();
        return excess[t]-1;
    }

private:
    void compile_g(){
        g_pos.resize(n+1);
        if(shuffle_edges) random_shuffle(edge_pool.begin(), edge_pool.end());
        for(auto &e:edge_pool){
            ++g_pos[get<0>(e)];
            ++g_pos[get<1>(e)];
        }
        for(int i=0;i<n;++i){
            g_pos[i+1]+=g_pos[i];
        }
        g.resize(g_pos.back());
        for(auto &e:edge_pool){
            int u, v; cap_t c, c_rev;
            tie(u, v, c, c_rev) = e;
            const int i = --g_pos[u], j = --g_pos[v];
            g[i] = Edge{v, j, c, 0};
            g[j] = Edge{u, i, c_rev, 0};
        }
    }
    void global_relabel(){
        q.reserve(n);
        fill(h.begin(), h.end(), n);
        fill(h_cnt.begin(), h_cnt.end(), 0);
        h_cnt[n] = 1;
        q.push_back(t);
        h[t] = 0;
        for(auto &e:buck) e.clear();
        for(auto &e:buck_all) e.clear();
        for(auto it = q.begin();it<q.end();++it){
            const int u = *it;
            if(u != t && excess[u]){
                hi = h[u];
                buck[h[u]].push_back(u);
            }
            if(u != t) buck_all[h[u]].push_back(u);
            ++h_cnt[h[u]];
            for(int i = g_pos[u],i_end = g_pos[u+1];i < i_end;++i){
                Edge const&e = g[i];
                if(g[e.rev].f && h[e.to] == n){
                    h[e.to] = h[u]+1;
                    q.push_back(e.to);
                }
            }
        }
        hi_all = h[q.back()];
        assert(h[s] == n);
        q.clear();
    }
    void push(int u, Edge &e, excess_t f){
        if(!excess[e.to]){
            buck[h[e.to]].push_back(e.to);
        }
        Edge&back = g[e.rev];
        e.f-=f;
        e.pushed += f;
        back.f+=f;
        back.pushed -= f;
        excess[e.to]+=f;
        excess[u]-=f;
    }
    void init_pr(){
        compile_g();
        cur.assign(n, 0);
        copy(g_pos.begin(), prev(g_pos.end()), cur.begin());
        h.resize(n);
        excess.assign(n, 0);
        buck.resize(2*n);
        buck_all.resize(n+1);
        h_cnt.assign(2*n, 0);
        h[s] = n;
        h_cnt[n] = 1;
        h_cnt[0] = n-1;
        excess[t] = 1;
    }
    void run_pr(){
        init_pr();
        for(int i = g_pos[s],i_end = g_pos[s+1];i < i_end;++i){
            push(s, g[i], g[i].f);
        }
        hi = hi_all = 0;
        if(global_relabeling) global_relabel();
        if(!buck[hi].empty())
            for(;hi>=0;){
                int u = buck[hi].back(); buck[hi].pop_back();
                int u_cur = cur[u];
                //discharge
                if(!min_cut_only || h[u] < n)
                    while(excess[u] > 0){
                        if(__builtin_expect(u_cur == g_pos[u+1], false)){
                            int new_h = 1e9;
                            for(int i = g_pos[u],i_end = g_pos[u+1];i < i_end;++i){
                                auto const&e = g[i];
                                if(e.f && new_h > h[e.to]+1){
                                    new_h = h[e.to]+1;
                                    u_cur = i;
                                }
                            }
                            ++h_cnt[new_h];
                            h[u] = new_h;
                            if(__builtin_expect(!--h_cnt[hi] && hi < n, false)){
                                // gap relabel
                                for(int j = hi;j <= hi_all;++j){
                                    for(auto &f:buck_all[j]) if(!min_cut_only || h[f] < n){
                                            --h_cnt[h[f]];
                                            h[f] = n+1;
                                        }
                                    buck_all[j].clear();
                                }
                            }
                            hi = h[u];
                        } else {
                            Edge &e_cur = g[u_cur];
                            if(e_cur.f && h[u] == h[e_cur.to]+1){
                                push(u, e_cur, min<excess_t>(excess[u], e_cur.f));
                            } else ++u_cur;
                        }
                    }
                if(h[u] < n) {
                    hi_all = max(hi_all, h[u]);
                    buck_all[h[u]].push_back(u);
                }
                cur[u] = u_cur;
                while(hi>=0 && buck[hi].empty()) --hi;
            }
    }

    int n, m, s, t, hi, hi_all;
    vector<tuple<int, int, cap_t, cap_t> > edge_pool;
    vector<int> g_pos;
    vector<Edge> g;
    vector<int> q, cur, h, h_cnt;
    vector<excess_t> excess;
    vector<vector<int> > buck, buck_all;

    vector<int> vct;
    vector<int> ptr;
    bool dfs(int v) {
        vct.push_back(v);
        if (v == n - 1) {
            return true;
        }
        while (ptr[v] < g_pos[v + 1]) {
            auto &e = g[ptr[v]];
            if (e.pushed > 0) {
                if (dfs(e.to)) {
                    e.pushed--;
                    g[e.rev].pushed++;
                    return true;
                }
            }
            ptr[v]++;
        }
        vct.pop_back();
        return false;
    }

public:
    void dump() {
        for (int i = 0; i < n; i++) {
            for (int j = g_pos[i]; j < g_pos[i + 1]; j++ ){
                auto &e = g[j];
                auto &re = g[e.rev];
                db2(i, e.to);
                db2(e.f, re.f);
            }
        }
        db("");
    }
    vector<vector<int>> restore() {

        ptr.assign(n, 0);
        for (int i = 0; i < n; i++) ptr[i] = g_pos[i];

        vector<vector<int>> ans;
        while (dfs(0)) {
//            dbv(vct);
            ans.push_back(vct);
            vct.clear();
        }
        return ans;
    }
};

Push_Relabel<int, int> gr(2);

/*long long push_count = 0;
long long arc_scans = 0;
template<typename flow_t = long long>
struct PushRelabel {
    struct Edge {
        int to, rev;
        flow_t f, c;
    };
    vector<vector<Edge> > g;
    vector<flow_t> ec;
    vector<Edge*> cur;
    vector<vector<int> > hs;
    vector<int> H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
    int add_edge(int s, int t, flow_t cap, flow_t rcap=0) {
        if (s == t) return -1;
        Edge a = {t, (int)g[t].size(), 0, cap};
        Edge b = {s, (int)g[s].size(), 0, rcap};
        g[s].push_back(a);
        g[t].push_back(b);
        return b.rev;
    }
    void add_flow(Edge& e, flow_t f) {
        ++push_count;
        Edge &back = g[e.to][e.rev];
        if (!ec[e.to] && f)
            hs[H[e.to]].push_back(e.to);
        e.f += f; e.c -= f;
        ec[e.to] += f;
        back.f -= f; back.c += f;
        ec[back.to] -= f;
    }
    flow_t max_flow(int s, int t) {
        push_count = arc_scans = 0;
        int v = g.size();
        H[s] = v;
        ec[t] = 1;
        vector<int> co(2*v);
        co[0] = v-1;
        for(int i=0;i<v;++i) cur[i] = g[i].data();
        for(auto &e:g[s]) add_flow(e, e.c);
        if(hs[0].size())
            for (int hi = 0;hi<2*v;) {
                int u = hs[hi].back();
                hs[hi].pop_back();
                while (ec[u] > 0) // discharge u
                    if (cur[u] == g[u].data() + g[u].size()) {
                        int hii = H[u];
                        H[u] = 1e9;
                        for(auto &e:g[u])
                            if (e.c && H[u] > H[e.to]+1)
                                H[u] = H[e.to]+1, cur[u] = &e;
                        if (++co[H[u]], !--co[hii] && hii < v)
                            for(int i=0;i<v;++i)
                                if (hii < H[i] && H[i] < v){
                                    --co[H[i]];
                                    H[i] = v + 1;
                                }
                        //hi = H[u];
                    } else if (cur[u]->c && H[u] == H[cur[u]->to]+1)
                        add_flow(*cur[u], min(ec[u], cur[u]->c));
                    else ++cur[u];
                if(hi) --hi;
                while (hi<2*v && hs[hi].empty()) ++hi;
            }
        return -ec[s];
    }
    vector<int> vct;
    vector<int> ptr;
    bool dfs(int v) {
        vct.push_back(v);
        if (v == g.size() - 1) {
            return true;
        }
        while (ptr[v] < (int)g[v].size()) {
            auto &e = g[v][ptr[v]];
            if (e.f > 0) {
                if (dfs(e.to)) {
                    e.f--;
                    return true;
                }
            }
            ptr[v]++;
        }
        vct.pop_back();
        return false;
    }

public:

    vector<vector<int>> restore() {
        int n = g.size();
        ptr.assign(n, 0);

        vector<vector<int>> ans;
        while (dfs(0)) {
//            dbv(vct);
            ans.push_back(vct);
            vct.clear();
        }
        return ans;
    }
};

PushRelabel<int> gr(2);*/

/*
struct Edge {
    int to, cap, flow;
};

struct Graph {
    int n;
    vector<vector<int> > e;
    vector<Edge> edges;
    vector<int> d, c;

    Graph() {}
    Graph(int _n) {
        n = _n;
        e.resize(n);
    }

    void add_edge(int from, int to, int cap) {
        e[from].push_back(edges.size());
        edges.push_back(Edge({to, cap, 0}));
        e[to].push_back(edges.size());
        edges.push_back(Edge({from, 0, 0}));
    }

    bool bfs() {
        d.assign(n, INF);
        c.assign(n, 0);
        vector<int> q(n);
        int qL = 0, qR = 0;
        d[0] = 0;
        q[qR++] = 0;
        while (qL < qR) {
            int v = q[qL++];
            for (int i = 0; i < (int)e[v].size(); i++) {
                Edge cur = edges[e[v][i]];
                if (d[cur.to] > d[v] + 1 && cur.flow < cur.cap) {
                    d[cur.to] = d[v] + 1;
                    q[qR++] = cur.to;
                }
            }
        }
        return d[n - 1] != INF;
    }

    int dfs(int v, int flow) {
        if (v == n - 1) return flow;
        if (flow == 0) return 0;
        for (int &i = c[v]; i < (int)e[v].size(); i++) {
            Edge cur = edges[e[v][i]];
            if (d[cur.to] != d[v] + 1) continue;
            int pushed = dfs(cur.to, min(flow, cur.cap - cur.flow));
            if (pushed > 0) {
                edges[e[v][i]].flow += pushed;
                edges[e[v][i] ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    ll max_flow(int S, int T) {
        ll flow = 0;
        while (bfs()) {
            while (int pushed = dfs(0, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }

    vector<int> vct;
    vector<int> ptr;
    bool dfs(int v) {
//        db(v);
        vct.push_back(v);
        if (v == n - 1) {
            return true;
        }
        while (ptr[v] < (int)e[v].size()) {
            auto &ed = edges[e[v][ptr[v]]];
            if (ed.flow > 0) {
                if (dfs(ed.to)) {
                    ed.flow--;
                    return true;
                }
            }
            ptr[v]++;
        }
        vct.pop_back();
        return false;
    }

public:
    vector<vector<int>> restore() {
        ptr.assign(n, 0);

        vector<vector<int>> ans;
        while (dfs(0)) {
//            dbv(vct);
            ans.push_back(vct);
            vct.clear();
        }
        return ans;
    }
};
Graph gr;*/

const int N = 1 << 18;
int vert[N];

struct segtree {
    int n, N;

    segtree() {}
    segtree(int _n) {
        n = _n;
        N = 1;
        while (N < n) N <<= 1;


//        gr = PushRelabel<int>(1 + n + 2*N + n + 1);
        gr = Push_Relabel<int, int>(1 + n + 2*N + n + 1);
//        gr = Graph(1 + n + 2*N + n + 1);
        for (int v = N - 1; v >= 1; v--) {
            gr.add_edge(1 + n + v, 1 + n + v * 2, INF);
            gr.add_edge(1 + n + v, 1 + n + v * 2 + 1, INF);
        }
        for (int i = 0; i < n; i++) {
            gr.add_edge(1 + n + N + i, 1 + n + N*2 + vert[i], 1);
        }
        for (int i = 0; i < n; i++) {
            gr.add_edge(0, 1 + i, 1);
            gr.add_edge(1 + n + N*2 + i, 1 + n + N*2 + n, 1);
        }
    }

    void get(int v, int from) {
        gr.add_edge(1 + from, 1 + n + v, 1);
    }

    void get(int l, int r, int from) {
        l += N;
        r += N;
        while (l <= r) {
            if (l & 1) get(l, from);
            if (!(r & 1)) get(r, from);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
    }
};

namespace hld {
    int par[N], heavy[N], h[N];
    int root[N], pos[N];
    int n;
    vector<vector<int> > e;
    segtree tree;

    int dfs(int v) {
        int sz = 1, mx = 0;
        for (int to : e[v]) {
            if (to == par[v]) continue;
            par[to] = v;
            h[to] = h[v] + 1;
            int cur = dfs(to);
            if (cur > mx) heavy[v] = to, mx = cur;
            sz += cur;
        }
        return sz;
    }

    template <typename T>
    void path(int u, int v, T op) {
        for (; root[u] != root[v]; v = par[root[v]]) {
            if (h[root[u]] > h[root[v]]) swap(u, v);
            op(pos[root[v]], pos[v]);
        }
        if (h[u] > h[v]) swap(u, v);
        op(pos[u] + 1, pos[v]);
    }

    void init(vector<vector<int> > _e) {
        e = _e;
        n = e.size();
        memset(heavy, -1, sizeof(heavy[0]) * n);
        par[0] = -1;
        h[0] = 0;
        dfs(0);
        for (int i = 0, cpos = 0; i < n; i++) {
            if (par[i] == -1 || heavy[par[i]] != i) {
                for (int j = i; j != -1; j = heavy[j]) {
                    root[j] = i;
                    vert[cpos] = j;
                    pos[j] = cpos++;
                }
            }
        }
        tree = segtree(n);
    }

    void get(int u, int v, int from) {
        path(u, v, [&](int l, int r) {
            tree.get(l, r, from);
        });
    }
}


vector<pair<pair<int, int>, pair<int, int>>> solve(vector<pair<int, int>> e1, vector<pair<int, int>> e2) {
    int n = e1.size() + 1;

    vector<vector<int>> e(n);
    for (auto o : e1) {
        e[o.first].push_back(o.second);
        e[o.second].push_back(o.first);
    }
    hld::init(e);

    vector<pair<pair<int, int>, pair<int, int>>> ans;
    for (int i = 0; i < n - 1; i++) {
        hld::get(e2[i].first, e2[i].second, i);
    }
    int res = gr.max_flow(0, 1 + n + 2*hld::tree.N + n);
    auto tmp = gr.restore();
//    db(tmp.size());
    assert(tmp.size() == res);
    for (auto v : tmp) {
        int v1 = v[1] - 1;
        int v2 = v[(int)v.size() - 2] - 1 - n - 2 * hld::tree.N;
        ans.push_back({{v2, hld::par[v2]}, e2[v1]});
    }
    return ans;
}

void print(vector<pair<pair<int, int>, pair<int, int>>> a) {
    printf("%d\n", (int)a.size());
    for (auto o : a) {
        printf("%d %d %d %d\n", o.first.first + 1, o.first.second + 1, o.second.first + 1, o.second.second + 1);
    }
}

void test() {
    int n = 2e5;
    mt19937 rnd;
    auto gen = [&](int n) {
        vector<pair<int, int>> e;
        for (int i = 1; i < n; i++) {
            e.push_back({rnd() % i, i});
        }
        return e;
    };
    auto e1 = gen(n);
    auto e2 = gen(n);
    solve(e1, e2);

}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
//  test();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<pair<int, int>> e1(n - 1), e2(n - 1);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &e1[i].first, &e1[i].second);
            e1[i].first--; e1[i].second--;
        }
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &e2[i].first, &e2[i].second);
            e2[i].first--; e2[i].second--;
        }

        print(solve(e1, e2));
    }

    return 0;
}