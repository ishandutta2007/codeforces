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

int query(int w){
  cout << "? " << w << endl;
  int h;
  cin >> h;
  return h;
}

int a[mn],b[mn];

void solve() {
  int n;
  cin >> n;
  int l=n,r=1e9;
  while(l<r){
    int mid=(l+r)/2;
    int h=query(mid);
    if(h==1)r=mid;
    else l=mid+1;
  }
  ll sum=l;
  ll ans=sum;
  for(int i=2;i<=n;i++){
    ll h = query(sum/i);
    if(h==0)continue;
    ans=min(ans,h*(sum/i));
  }
  cout << "! " << ans << endl;
}

int main(){
  //cin.tie(0);
  //cin.sync_with_stdio(false);
  int tc=1;
  //cin >> tc;
  while(tc--){
    solve();
  }
}