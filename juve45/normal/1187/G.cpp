#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
 
struct Flow {
    const static int MAX_EDGES = 551005;
    const static int MAX_NODES = 6105;
    const int INF = 1e9 + 50;
 
    int S = MAX_NODES - 2, D = MAX_NODES - 1;
 
    int G[MAX_NODES];
    struct Edge {
        int vec, flow, cap, cost, rev, nxt;
    };
    Edge E[2 * MAX_EDGES];
    int edges = 0;
 
    int ParentNode[MAX_NODES], ParentEdge[MAX_NODES], Dist[MAX_NODES];
    bool InQ[MAX_NODES];
    queue<int> Q;
 
    Flow() {
        Reset();
    }
 
    void setSource(int s) {
        S = s;
    }
    void setSink(int d) {
        D = d;
    }
 
    void _addEdge(int a, int b, int cap, int cost, int rev) {
        ++edges;
        E[edges] = (Edge) {b, 0, cap, cost, rev, G[a]};
        G[a] = edges;
    }
    void AddEdge(int a, int b, int cap, int cost) {
        _addEdge(a, b, cap, cost, edges + 2);
        _addEdge(b, a, 0, -cost, edges);
    }
 
    bool Bellman() {
        memset(ParentNode, 0, sizeof(ParentNode));
 
        Dist[S] = 0;
        Q.push(S);
 
 
        while(!Q.empty()) {
            int top = Q.front();
            InQ[top] = 0;
            Q.pop();
 
            for(int i=G[top]; i; i=E[i].nxt) {
                int vec = E[i].vec;
                if(E[i].flow < E[i].cap && (ParentNode[vec] == 0 || Dist[vec] > Dist[top] + E[i].cost)) {
                    Dist[vec] = Dist[top] + E[i].cost;
                    ParentNode[vec] = top;
                    ParentEdge[vec] = i;
 
                    if(!InQ[vec]) {
                        Q.push(vec);
                        InQ[vec] = 1;
                    }
                }
            }
        }
 
        return ParentNode[D] != 0;
    }
 
    void Reset() {
        edges = 0;
        memset(G, 0, sizeof(G));
    }
 
    int MFMC() {
        int cost = 0, flow = 0;
 
        while(Bellman()) {
            int M = INF;
 
            for(int node = D; node != S; node = ParentNode[node]) {
                int ei = ParentEdge[node];
                M = min(M, E[ei].cap - E[ei].flow);
            }
 
            for(int node = D; node != S; node = ParentNode[node]) {
                int ei = ParentEdge[node],
                    ri = E[ei].rev;
 
                E[ei].flow += M;
                E[ri].flow -= M;
 
                cost += E[ei].cost * M;
            }
 
            flow += M;
        }
        dbg(flow);
        return cost;
    }
 
};
Flow F;

const int MAX_DAY = 101;

int n, m, k, c, d, a[55], x, y;

int vert(int nr, int day) {
  return 51 * day + nr;
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> k >> c >> d;

  for(int i = 1; i <= k; i++) {
    cin >> a[i];
    F.AddEdge(F.S, vert(a[i], 0), 1, 0);
    // F.AddEdge(vert(a[i], 50), F.D, 1, 0);
  }

  for(int i = 1; i <= m; i++) {
    cin >> x >> y;
    for(int day = 0; day < MAX_DAY; day++) {
      for(int cost = 0; cost < 50; cost ++) {
        F.AddEdge(vert(x, day), vert(y, day + 1), 1, (2 * cost + 1) * d);
        F.AddEdge(vert(y, day), vert(x, day + 1), 1, (2 * cost + 1) * d);
      }
    }
  }
  // dbg(F.edges);

  for(int day = 0; day <= MAX_DAY; day++) {
    // dbg(F.edges);

    for(int i = 1; i <= n; i++)
      F.AddEdge(vert(i, day), vert(i, day + 1), 51, 0);

    for(int i = 0; i < k; i++)
      F.AddEdge(vert(1, day), F.D, 1, c * day);
  }
  dbg("ok", F.edges);
  cout << F.MFMC() << '\n';
}   

// K + M * DAY * K + DAY * N + DAY * K
// 50 + 50 * 100 * 50 + 50 * 100 + 50 * 100