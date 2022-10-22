#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
const int mn = 2e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 1e9+7;

struct DSU {
  vi p;
  DSU(int n) : p(n) {
    rep(i, 0, n) p[i] = i;
  }
  int find(int x) {
   // cerr << x << endl;
    return p[x] == x ? x : p[x] = find(p[x]);
  }
  void join(int x, int y) {
    p[find(x)] = find(y);
  }
};

struct Edge {
  int a, b, c;
};

void solve() {
  int n,m;
  cin >> n>>m;
  vector<Edge> edges(m);
  int tar = -1;
  vector<DSU> dsu2(30, DSU(n));
  rep(i,0,m) {
    cin >> edges[i].a >> edges[i].b >> edges[i].c;
    edges[i].a--;
    edges[i].b--;
    if(edges[i].c %2==0){
      if(tar==-1) tar = edges[i].a;
      for(int j=1;j<30;j++){
        dsu2[j].join(edges[i].a,tar);
        dsu2[j].join(edges[i].b,tar);
      }
    }
  }
  vector<DSU> dsu(30, DSU(n));
  for(int i=0;i<30;i++){
    for(Edge &e : edges) if((e.c>>i)&1){
      dsu[i].join(e.a, e.b);
      dsu2[i].join(e.a,e.b);
    }
  }
  int q;
  cin >> q;
  while(q--){
    int u,v;
    cin>>u>>v;
    int ans = [&](){
      for(int i=0;i<30;i++)if(dsu[i].find(u-1)==dsu[i].find(v-1)){
        return 0;
      }
      for(int i=1;i<30;i++)if(tar!=-1&&dsu2[i].find(u-1)==dsu2[i].find(tar)){
        return 1;
      }
      return 2;
    }();
    printf("%d\n",ans);
  }
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc=1;
  //cin >> tc;
  while(tc--){
    solve();
  }
}