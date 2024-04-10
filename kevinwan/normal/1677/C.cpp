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
const int mn = 1e6+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;

int nxt[mn],a[mn],b[mn];
bool vis[mn];

void solve(){
  int n;
  cin >> n;
  rep(i,0,n)cin >> a[i];
  rep(i,0,n)cin >> b[i];
  rep(i,0,n)nxt[a[i]]=b[i];
  rep(i,1,n+1)vis[i]=0;
  ll ans=0;
  vi v;
  rep(i,1,n+1){
    if(vis[i])continue;
    int num=1;
    for(int j=nxt[i];j!=i;j=nxt[j]){
      num++;
      vis[j]=1;
    }
    v.push_back(num);
  }
  sort(all(v),[](int a,int b){
    if(a%2!=b%2)return a%2<b%2;
    return a>b;
  });
  int d=n-1;
  for(int x:v){
    rep(j,0,x/2)ans+=d*2,d-=2;
  }
  printf("%lld\n",ans);
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