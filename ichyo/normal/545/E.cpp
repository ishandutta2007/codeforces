// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

struct Edge{
    int dst;
    LL cost;
    int idx;
};

const LL INF = 1000000000000000000LL;

typedef vector<Edge> Node;
typedef vector<Node> Graph;

void add_edge(Graph& G, int a, int b, LL c, int idx) {
    G[a].push_back({b, c, idx});
}
int main(){
    iostream_init();
    int N, M;
    while(cin >> N >> M){
        Graph G(N);
        REP(i, M) {
            int a, b;
            LL c;
            cin >> a >> b >> c;
            a--; b--;
            add_edge(G, a, b, c, i+1);
            add_edge(G, b, a, c, i+1);
        }
        int start;
        cin >> start;
        start--;
        typedef tuple<LL, LL, int, int> P;
        priority_queue<P, vector<P>, greater<P>> que;
        vector<LL> dist(G.size(), INF);
        vector<LL> min_edge(G.size(), INF);
        que.push(P(0, 0, start, -1));
        dist[start] = 0;
        LL sum = 0;
        vector<int> ans;
        vector<bool> used(N);
        while(!que.empty()){
            P p = que.top(); que.pop();
            LL c;
            LL ec;
            int v, idx;
            tie(c, ec, v, idx) = p;
            if(c > dist[v]) continue;
            if(used[v]) continue;
            used[v] = true;
            sum += ec;
            if(idx != -1) ans.push_back(idx);
            for(auto& e : G[v]){
                if(dist[e.dst] >= dist[v] + e.cost){
                    dist[e.dst] = dist[v] + e.cost;
                    que.push(P(dist[e.dst], e.cost, e.dst, e.idx));
                }
            }
        }
        cout << sum << endl;
        REP(i, ans.size()) {
            cout << ans[i] << " \n"[i+1 == ans.size()];
        }
    }
    return 0;
}

/* vim:set foldmethod=marker: */