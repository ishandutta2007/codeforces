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
const int mn = 5e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;
 
int a[mn],b[mn];
vi g[mn];

bool vis[mn],ins[mn],cycle;
void dfs(int x){
  vis[x]=ins[x]=1;
  for(int y:g[x]){
    if(!vis[y])dfs(y);
    else if(ins[y])cycle=1;
  }
  ins[x]=0;
}
 
void solve() {
  int n;
  cin >> n;
  vi f(n+1);
  cycle=0;
  rep(i,1,n+1) cin >> a[i],f[a[i]]++,g[i].clear(),vis[i]=ins[i]=0;
  int ma = max_element(f.begin()+1,f.end()) - f.begin();
  rep(i,1,n+1) cin >> b[i];
  rep(i,1,n+1){
    if(a[i]!=ma&&b[i]!=ma)g[a[i]].push_back(b[i]);
  }
  rep(i,1,n+1){
    if(!vis[i])dfs(i);
  }
  printf("%s\n",cycle?"WA":"AC");
}
 
int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc=1;
  cin >> tc;
  while(tc--){
    solve();
  }
}