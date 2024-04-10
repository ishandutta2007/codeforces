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


int a[mn];
void solve(){
  int n,k;
  cin >> n >> k;
  rep(i,0,n)cin>>a[i];
  ll ans=1;
  rep(i,0,k)ans*=i+1,ans%=mod;
  rep(i,0,n-k){
    if(a[i]>i)ans=0;
    if(a[i]==-1)ans*=k+i+1;
    else if(a[i]==0)ans*=k+1;
    ans%=mod;
  }
  rep(i,n-k,n)if(a[i]!=0&&a[i]!=-1)ans=0;
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