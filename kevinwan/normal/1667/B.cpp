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
const ll mod = 1e9+7;

struct BIT {
  vll bit;
  int n;
  BIT(int nn): n(nn), bit(2*nn+1,inf) {}
  void upd(int a,ll b){
    for(a+=n;a<bit.size();a+=a&-a) bit[a]=min(bit[a],b);
  }

  ll qry(int a){
    ll ans=inf;
    for(a+=n;a;a-=a&-a) ans=min(ans,bit[a]);
    return ans;
  }

  ll bs(ll v){
    int cur=0;
    for(int i=1<<21;i;i>>=1){
      if(cur+i<bit.size()&&bit[cur+i]>=v) cur+=i;
    }
    return cur+1-n;
  }
};
void solve() {
  int n;
  cin >> n;
  vll a(n+1), dp(n+1);
  for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
  BIT bit(2*n+1);
  bit.upd(0,0);
  for(int i=1;i<=n;i++){
    ll val = -bit.bs(a[i]);
    dp[i] = max(i+val, dp[i-1]-1);
    if(a[i]==a[i-1])dp[i]=max(dp[i],dp[i-1]);
    bit.upd(-(dp[i]-i), a[i]);
  }
  printf("%lld\n", dp[n]);
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