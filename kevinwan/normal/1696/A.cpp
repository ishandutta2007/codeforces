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

const int mn = 1e6+10;

void solve() {
  ll n,z;
  cin >> n >> z;
  ll ans=0;
  for(int i=0;i<n;i++){
    ll x;
    cin >> x;
    x|=z;
    ans=max(ans,x);
  }
  printf("%lld\n",ans);
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--)solve();
}