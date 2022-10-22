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
const int mn = 4e3+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;

string s[mn];

vi g[mn];
int sc[mn];

ll p2(ll x) {
  ll ans = 1;
  for(ll a=2;x;x>>=1,a=a*a%mod)if(x&1)ans = ans*a%mod;
  return ans;
}

bool vis[mn];
int ccs[mn],sz[mn];
void dfs(int x){
  cerr << x << " dfs " << g[x].size() << endl;
  vis[x]=1;
  ccs[x]=sc[x];
  sz[x]=1;
  for(int y:g[x]){
    if(!vis[y])dfs(y),ccs[x]^=ccs[y],sz[x]+=sz[y];
  }
}

void solve() {
  int n,m;
  cin >> n>> m;
  rep(i,0,n) cin >> s[i];
  int num = 0;
  int req = -1;
  rep(i,0,n){
    rep(j,0,m){
      if(s[i][j]=='?'){
        num++;
        g[i].push_back(j+n);
        g[j+n].push_back(i);
      }
      else {
        sc[i]^=s[i][j]-'0';
        sc[j+n]^=s[i][j]-'0';
      }
    }
  }
  if(n%2==0&&m%2==0){
    printf("%lld\n",p2(num));
  }
  else if(n%2==1&&m%2==0){
    int val = -1;
    num-=m;
    for(int j=0;j<m;j++)if(g[n+j].size()==0){
      num++;
      if(val==-1)val=sc[n+j];
      else if(val!=sc[n+j]){
        printf("0\n");
        return;
      }
    }
    if(val==-1)num++;
    printf("%lld\n",p2(num));
  }
  else if(n%2==0&&m%2==1){
    int val=-1;
    num-=n;
    for(int i=0;i<n;i++)if(g[i].size()==0){
      num++;
      if(val==-1)val=sc[i];
      else if(val!=sc[i]){
        printf("0\n");
        return;
      }
    }
    if(val==-1)num++;
    printf("%lld\n",p2(num));
  }
  else{
    num-=n+m;
    vi even, odd;
    for(int i=0;i<n+m;i++)if(!vis[i]){
      dfs(i);
      num++;
      if(sz[i]%2==0)even.push_back(ccs[i]);
      else odd.push_back(ccs[i]);
      cerr<<i<<endl;
    }
    cerr << n+m << endl;
    bool ok = 1;
    for(int p:even)if(p!=0)ok=0;
    for(int p:odd)if(p!=odd[0])ok=0;
    bool two = (odd.size()==0);
    if(!ok)printf("0\n");
    else if(two)printf("%lld\n",p2(num)*2%mod);
    else printf("%lld\n",p2(num));
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