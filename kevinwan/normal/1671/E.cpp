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
const ll mod = 998244353;

void solve() {
  int n;
  cin >> n;
  string s;
  vector<string> t(1<<n);
  cin >> s;
  for(int i=(1<<n)-2;i>=0;i--) t[i+1] = s[i];
  ll ans = 1;
  for(int i=(1<<(n-1))-1;i>=1;i--) {
    if(t[i*2]!=t[i*2+1])ans*=2,ans%=mod;
    if(t[i*2]<t[i*2+1])t[i]=t[i*2]+t[i]+t[i*2+1];
    else t[i]=t[i*2+1]+t[i]+t[i*2];
    t[i*2].clear();
    t[i*2+1].clear();
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