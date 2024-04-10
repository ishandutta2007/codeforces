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

void solve() {
  int n;
  ll x;
  cin >> n >> x;
  vector<ll>a(n);
  for (auto& x: a) cin >> x;
  ll ans=0;
  ll mi=inf,ma=-inf;
  for(int i=0;i<n-1;i++) ans += abs(a[i+1]-a[i]);
  for(int i=0;i<n;i++)mi=min(mi,a[i]),ma=max(ma,a[i]);
  if(1<=mi)ans+=min({a[0]-1,(mi-1)*2,a[n-1]-1});
  if(ma<=x)ans+=min({x-a[0],(x-ma)*2,x-a[n-1]});
  printf("%lld\n", ans);
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