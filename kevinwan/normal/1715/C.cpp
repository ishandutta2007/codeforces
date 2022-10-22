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

ll a[mn];
ll change(ll n, ll i){
  return (i+1)*(n-i-1);
}
void solve() {
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>a[i];
  ll ans=0;
  for(int i=0;i<n-1;i++){
    if(a[i]!=a[i+1])ans+=change(n,i);
  }
  for(int i=0;i<m;i++){
    ll ind,x;
    cin >>ind >> x;
    ind--;
    ll lef=-int(ind>0&&a[ind-1]!=a[ind]), rig=-int(ind<n-1&&a[ind]!=a[ind+1]);
    a[ind]=x;
    lef+=int(ind>0&&a[ind-1]!=a[ind]),rig+=int(ind<n-1&&a[ind]!=a[ind+1]);
    ans +=lef*change(n,ind-1)+rig*change(n,ind);
    printf("%lld\n",ans+ll(n)*(n+1)/2);
  }
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