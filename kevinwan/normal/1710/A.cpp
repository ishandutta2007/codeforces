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
bool test(ll n, ll m, ll k) {
  ll ex=0;
  ll u=0;
  for(int i=0;i<k;i++){
    if(a[i]>=2*m){
      ex+=a[i]/m-2;
      u+=a[i]/m;
    }
  }
  if(u<n)return 0;
  if(n%2==1&&ex==0)return 0;
  return 1;
}

void solve() {
  ll n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<k;i++)cin>>a[i];
  printf("%s\n",test(n,m,k)||test(m,n,k)?"Yes":"No");
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