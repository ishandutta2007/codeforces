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
void solve() {
  int n,x;
  cin >> n>>x;
  for(int i=0;i<n;i++)cin>>a[i];
  int ans=0;
  ll lo=inf,hi=-inf;
  for(int i=0;i<n;i++){
    lo=min(lo,(ll)a[i]);
    hi=max(hi,(ll)a[i]);
    if(hi-lo>2*x){
      ans++;
      hi=lo=a[i];
    }
  }
  printf("%d\n",ans);
}
 
int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  for(int tcc=1;tcc<=tc;tcc++){
    //printf("Case #%d: ",tcc);
    solve();
  }
}