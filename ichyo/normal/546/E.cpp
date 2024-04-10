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
const int INF = 1e9;
struct Edge{
    int dst, cap, rev;
};
typedef vector<Edge> Node;
typedef vector<Node> Graph;

struct Dinic{
    Graph G;
    vector<int> level;
    vector<int> iter;
    
    Dinic(int N) : G(N), level(N), iter(N) {}

    void bfs(int s){
        level.assign(G.size(), -1);
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(const auto& e : G[v]){
                if(e.cap > 0 && level[e.dst] < 0){
                    level[e.dst] = level[v] + 1;
                    que.push(e.dst);
                }
            }
        }
    }

    int dfs(int v, int t, int f){
        if(v == t) return f;
        for(int& i = iter[v]; i < G[v].size(); i++){
            Edge& e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.dst]){
                int d = dfs(e.dst, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.dst][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    void add_edge(int src, int dst, int cap){
        G[src].push_back({dst, cap, (int)G[dst].size()});
        G[dst].push_back({src, 0, (int)G[src].size() - 1});
    }

    int max_flow(int src, int dst){
        int flow = 0;
        while(true){
            bfs(src);
            if(level[dst] < 0) break;
            iter.assign(G.size(), 0);
            while(true){
                int f = dfs(src, dst, INF);
                if(f <= 0) break;
                flow += f;
            }
        }
        return flow;
    }
};
int main(){
    iostream_init();
    int N, M;
    cin >> N >> M;
    const int SRC = 2 * N;
    const int DST = SRC + 1;
    Dinic dinic(DST + 1);
    int flow = 0;
    vector<int> A(N);
    vector<int> B(N);
    REP(i, N) {
        int x;
        cin >> x;
        A[i] = x;
        flow += x;
        dinic.add_edge(SRC, i, x);
    }
    int flow2 = 0;
    REP(i, N) {
        int y;
        cin >> y;
        B[i] = y;
        flow2 += y;
        dinic.add_edge(N + i, DST, y);
    }

    if(flow != flow2) {
        cout << "NO" << endl;
        return 0;
    }

    REP(i, N) dinic.add_edge(i, i + N, INF);

    bool edge[100][100] = {};
    REP(i, N) edge[i][i] = true;
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a][b] = edge[b][a] = true;
        dinic.add_edge(a, N + b, INF);
        dinic.add_edge(b, N + a, INF);
    }

    int f = dinic.max_flow(SRC, DST);
    if(f != flow) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    Graph G = dinic.G;
    int ans[100][100] = {};
    REP(i, N) for(Edge e : G[i]){
        if(e.cap < INF) {
            int d = INF - e.cap;
            if(!(e.dst - N >= 0 && e.dst - N < N)) continue;
            ans[i][e.dst - N] += d;
        }
    }
    REP(i, N) {
        REP(j, N) {
            cout << ans[i][j];
            if(j == N-1) cout << endl;
            else cout << " ";
        }
    }
    REP(i, N) {
        REP(j, N) A[i] -= ans[i][j];
    }
    REP(i, N) {
        REP(j, N) B[j] -= ans[i][j];
    }
    REP(i, N) assert(A[i] == 0);
    REP(i, N) assert(B[i] == 0);
    REP(i, N) REP(j, N) if(ans[i][j]) assert(edge[i][j]);
    return 0;
}

/* vim:set foldmethod=marker: */