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
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const ll INF = 10000000000000LL;
const double EPS = 1e-8;
const int MOD = 1000000007;
struct edge{
  int u, v;
  ll c;
  edge() {}
  edge(int u, int v, ll c) :
    u(u), v(v), c(c) {}
  bool operator < (const edge& e) const {
    return c > e.c; // rev
  }
};
typedef vector<edge> edges;
typedef vector<edges> graph;
typedef pair<ll, ll> P;
int main(){
  int N, M;
  while(cin>>N>>M && N){
    graph g(N);
    while(M--){
      int a, b, c;
      cin>>a>>b>>c;
      a--, b--;
      g[a].push_back(edge(a, b, c));
      g[b].push_back(edge(b, a, c));
    }
    vector< vector<P> > ban(N);
    REP(i, N){
      int K; cin>>K;
      ll tmp[100001];
      REP(j, K) cin>>tmp[j];
      int idx = 0;
      REP(j, K){
        if(j == K - 1 || tmp[j + 1] - tmp[j] > 1){
          ban[i].push_back(P(tmp[idx], tmp[j] + 1));
          idx = j + 1;
        }
      }
    }
    /*
    REP(i, N){
      printf("%d(%d):", i, ban[i].size());
      REP(j, ban[i].size()) printf("(%d, %d) ", ban[i][j].first, ban[i][j].second);
      cout<<endl;
    }
    */
    priority_queue<edge> que;
    ll dist[100001] = {};
    REP(i, N) dist[i] = INF;
    dist[0] = 0;
    if(ban[0].size() > 0 && ban[0][0].first == 0) dist[0] = ban[0][0].second;
    que.push(edge(-1, 0, dist[0]));
    ll ans = INF;
    while(!que.empty()){
      edge s = que.top(); que.pop();
      //printf("%d %d\n", s.v + 1, s.c);
      if(s.v == N-1){
        ans = s.c;
        break;
      }
      FORIT(it, g[s.v]){
        ll nc = it->c + s.c;
        int nv = it->v;
        if(dist[nv] <= nc) continue;
        if(ban[nv].size() > 0){
          int idx = distance(ban[nv].begin(), lower_bound(ban[nv].begin(), ban[nv].end(), P(nc, INF))) - 1;
          if(nv != N - 1 && idx >= 0){
            nc = max(nc, ban[nv][idx].second);
          }
        }
        if(dist[nv] <= nc) continue;
        dist[nv] = nc;
        que.push(edge(s.v, nv, nc));
      }
    }
    if(ans == INF) ans = -1;
    cout<<ans<<endl;
  }
  return 0;
}