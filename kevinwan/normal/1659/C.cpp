#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
const int mn = 2e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 1e9+7;



void solve() {
  int n,a,b;
  cin >> n >> b >> a;
  vector<ll> v(n+1);
  v[0]=0;
  for(int i=1;i<=n;i++)cin>>v[i];
  int pos=max(0,n-1-b/a);
  ll ans=v[pos]*(a+b);
  for(int i=pos+1;i<=n;i++)ans+=a*(v[i]-v[pos]);
  printf("%lld\n", ans);
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--){
    solve();
  }
}