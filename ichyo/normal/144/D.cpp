#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
/* structure */
const int INF = 100000000;
typedef int Weight;
struct Edge{
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) {}
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

int main(){
  int n,m,s,l;
  cin>>n>>m>>s;
  s--;
  Graph g(n);
  REP(i,m){
    int p,q,r;
    cin>>p>>q>>r;
    p--;q--;
    g[p].push_back(Edge(p,q,r));
    g[q].push_back(Edge(q,p,r));
  }
  cin>>l;
  int ans = 0;
  int sz = g.size();
  vector<Weight> dist(sz, INF); dist[s] = 0;
  vector<int> prev(sz, -1);
  priority_queue<Edge> que;
  for(que.push(Edge(-2,s,0)); !que.empty();){
    Edge e = que.top(); que.pop();
    if(prev[e.dst] != -1) continue;
    prev[e.dst] = e.src;
    FORIT(f,g[e.dst]){
      if(dist[f->dst] > e.weight + f->weight){
        dist[f->dst] = e.weight + f->weight;
        que.push(Edge(f->src, f->dst, dist[f->dst]));
      }
    }
  }
  REP(i,n){
    if(dist[i]==l)ans++;
    if(dist[i] < l){
      FORIT(f,g[i]){
        if(dist[i] + f->weight > l && dist[f->dst] + (f->weight-(l-dist[i])) >= l){
          ans ++;
          if(i < f->dst && dist[i] + dist[f->dst] + f->weight == 2 * l) ans --;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}