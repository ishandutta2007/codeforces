#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

struct Edge {
  int src, dst;
  Edge(int src, int dst) :
    src(src), dst(dst) { }
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

Graph g1, g2;
Edges e[100000], b;
vector <vector <int> > v;
int a[100000];

void visit(const Graph & g, int v, int u,
    Edges& brdg, vector< vector<int> >& tecomp,
    stack<int>& roots, stack<int>& S, vector<bool>& inS,
    vector<int>& num, int& time) {
  num[v] = ++time;
  S.push(v); inS[v] = true;
  roots.push(v);
  FOR(e, g[v]) {
    int w = e->dst;
    if (num[w] == 0)
      visit(g, w, v, brdg, tecomp, roots, S, inS, num, time);
    else if (u != w && inS[w])
      while (num[roots.top()] > num[w]) roots.pop();
  }
  if (v == roots.top()) {
    brdg.push_back(Edge(u, v));
    tecomp.push_back(vector<int>());
    while (1) {
      int w = S.top(); S.pop(); inS[w] = false;
      tecomp.back().push_back(w);
      if (v == w) break;
    }
    roots.pop();
  }
}
void bridge(const Graph& g, Edges& brdg, vector< vector<int> >& tecomp) {
  const int n = g.size();
  vector<int> num(n);
  vector<bool> inS(n);
  stack<int> roots, S;
  int time = 0;
  REP(u, n) if (num[u] == 0) {
    visit(g, u, n, brdg, tecomp, roots, S, inS, num, time);
    brdg.pop_back();
  }
}

int dfs(int x, int y, int z)
{
    int i;
    
    if (x == z) return 0;
    
    for (i = 0; i < g2[x].size(); i++) {
        int t;
        
        if (g2[x][i].dst == y) continue;
        
        t = dfs(g2[x][i].dst, x, z);
        
        if (t >= 0) return t + 1;
    }
    
    return -1;
}

int main()
{
    int n, m, k, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        e[x].push_back(Edge(x, y));
        e[y].push_back(Edge(y, x));
    }
    
    for (i = 0; i < n; i++) {
        g1.push_back(e[i]);
        
        e[i].clear();
    }
    
    bridge(g1, b, v);
    
    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < v[i].size(); j++) {
            a[v[i][j]] = i;
        }
    }
    
    for (i = 0; i < b.size(); i++) {
        int x = a[b[i].src];
        int y = a[b[i].dst];
        
        e[x].push_back(Edge(x, y));
        e[y].push_back(Edge(y, x));
    }
    
    for (i = 0; i < v.size(); i++) g2.push_back(e[i]);
    
    scanf("%d", &k);
    
    for (i = 0; i < k; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        printf("%d\n", dfs(a[x - 1], -1, a[y - 1]));
    }
    
    return 0;
}