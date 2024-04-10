#include "bits/stdc++.h"
 
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int mn = 1e4+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;

struct flow {
  ll st,len;
  bool lon;
};

vector<flow> ans[mn];
ll a[mn];
vi g[mn];
bool vis[mn];
int n,m;
void dfs(int x){
  vis[x]=1;
  vector<flow> vf;
  if(a[x]!=0)vf.push_back({0,a[x]%mod,a[x]>=n});
  for(int y:g[x]){
    if(!vis[y])dfs(y);
    for(flow &f : ans[y])vf.push_back({f.st+1,f.len,f.lon});
  }
  sort(all(vf),[](const flow&a,const flow&b){return a.st<b.st;});
  if(vf.size()==0)return;
  flow cf {vf[0].st,0,0};
  for(flow &f : vf){
    if(cf.lon||cf.st+cf.len>=f.st){
      cf.lon=(cf.lon||f.lon||cf.len+f.len>=n);
      cf.len=(cf.len+f.len)%mod;
    }
    else {
      ans[x].push_back(cf);
      cf = f;
    }
  }
  ans[x].push_back(cf);
}

void solve() {
  cin >> n >> m;
  for(int i=1;i<=n;i++)ans[i].clear(),g[i].clear(),vis[i]=a[i]=0;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    g[b].push_back(a);
  }
  int s;
  for(int i=1;i<=n;i++)if(!vis[i])dfs(i),s=i;
  // cerr << s << endl;
  printf("%lld\n",ans[s].size()==0?0:(ans[s].back().st+ans[s].back().len)%mod);
}
 
int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  for(int tcc=1;tcc<=tc;tcc++){
    //printf("Case #%d: ",tcc);
    solve();
  }
}