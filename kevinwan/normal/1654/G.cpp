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

vi g[mn];
bool base[mn];
int dis[mn];
vi bri[mn];
int bes[mn];
int rem[mn];
bool vis[mn];

void solve() {
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)cin >> base[i];
  vector<pii> edges;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
    edges.emplace_back(a,b);
  }
  {
    queue<int> q;
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=n;i++)if(base[i])q.push(i),dis[i]=0;
    while(!q.empty()){
      int x = q.front();
      q.pop();
      for(int y:g[x]){
        if(dis[y] == -1){
          dis[y] = dis[x]+1;
          q.push(y);
        }
      }
    }
  }
  for(auto [a,b]: edges){
    if(dis[a] == dis[b]){
      bri[dis[a]].push_back(a);
      bri[dis[a]].push_back(b);
    }
  }
  for(int i=1;i<=n;i++)bes[i] = dis[i];
  auto prop = [&](int h, vi &v) {
    sort(all(v));
    v.erase(unique(all(v)), end(v));
    deque<int> q;
    memset(rem,0x3f,sizeof(rem));
    memset(vis,0,sizeof(vis));
    for(int x:v)q.push_back(x),rem[x]=h;
    while(q.size()){
      int x = q.front();
      q.pop_front();
      if(vis[x])continue;
      vis[x] = 1;
      if(dis[x]>=rem[x])bes[x]=min(bes[x],h);
      for(int y:g[x]){
        if(dis[y]==dis[x]){
          rem[y]=min(rem[y], rem[x]+1);
          q.push_back(y);
        }
        else if(dis[y]>dis[x]){
          int d = max(rem[x], dis[y])-rem[x];
          rem[y]=min(rem[y],rem[x]+d);
          if(d)q.push_back(y);
          else q.push_front(y);
        }
      }
    }
  };
  for(int i=0;i<=n;i++)if(bri[i].size()) {
    prop(i,bri[i]);
  }
  for(int i=1;i<=n;i++) printf("%d ", dis[i]*2-bes[i]);
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