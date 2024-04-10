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
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod=1e9+7;

const int mn = 1e6+10;
ll fact[mn];
ll po(ll a, ll b=mod-2){
  ll ans=1;
  for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
  return ans;
}
ll ch(ll a,ll b){
  if(a==-1&&b==0)return 1;
  if(b<0||b>a)return 0;
  return fact[a]*po(fact[a-b]*fact[b]%mod)%mod;
}
int a[mn];
void solve() {
  int n;
  cin >> n;
  for(int i=0;i<=n;i++)cin>>a[i];
  fact[0]=1;
  for(int i=1;i<mn;i++)fact[i]=fact[i-1]*i%mod;
  ll ans=0;
  for(int i=0;i<=n+1;i++){
    ans+=ch(a[i]-1+i,i);ans%=mod;
    if(i!=0)for(int j=a[i];j<a[i-1];j++){
      ans+=ch(i-1+j,i-1);ans%=mod;
    }
  }
  ans--;
  ans%=mod;
  if(ans<0)ans+=mod;
  printf("%lld\n",ans);
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc=1;
  //cin >> tc;
  while(tc--)solve();
}