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
const int mn = 3e6+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;
vi g[mn];
bool vis[mn];
int ans[mn];
void solve() {
  int n,q;
  cin >> n >> q;
  memset(ans,-1,sizeof(ans));
  for(int i=0;i<q;i++){
    int a,b,x;
    cin >> a >> b >> x;
    a--,b--;
    for(int j=0;j<30;j++){
      if((x>>j)&1){
        g[a*30+j].push_back(b*30+j);
        g[b*30+j].push_back(a*30+j);
        if(a==b)ans[a*30+j]=1;
      }
      else{
        ans[a*30+j]=ans[b*30+j]=0;
      }
    }
  }
  for(int i=0;i<30*n;i++){
    if(ans[i]==0){
      for(int j:g[i])ans[j]=1;
    }
  }
  for(int i=0;i<30*n;i++){
    if(ans[i]==-1){
      ans[i]=0;
      for(int j:g[i])ans[j]=1;
    }
  }
  for(int i=0;i<n;i++){
    int res=0;
    for(int j=0;j<30;j++)res+=ans[i*30+j]<<j;
    printf("%d ",res);
  }
  printf("\n");
}
 
int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc=1;
  //cin >> tc;
  for(int tcc=1;tcc<=tc;tcc++){
    //printf("Case #%d: ",tcc);
    solve();
  }
}