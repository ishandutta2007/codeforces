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
  cin >> n;
  vll a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  ll ans = inf;
  for(int z=0;z<n;z++){
    ll cand = 0;
    ll cur = 0;
    for(int i=z+1;i<n;i++){
      ll num = cur/a[i]+1;
      //cerr<<num<<endl;
      cand += num;
      cur = num*a[i];
    }
    cur = 0;
    for(int i=z-1;i>=0;i--){
      ll num = cur/a[i]+1;
      //cerr<<num<<endl;
      cand += num;
      cur = num*a[i];
    }
    ans=min(ans,cand);
  }
  printf("%lld\n",ans);
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