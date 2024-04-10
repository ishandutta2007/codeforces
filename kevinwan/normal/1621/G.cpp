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

struct BIT {
  int n;
  vector<ll> bit;
  BIT(int n) : n(n), bit(n+1, 0) {}
  void upd(int a,ll b){for(a+=2;a<=n;a+=a&-a)bit[a]+=b;}
  ll qry(int a){ll s=0;for(a+=2;a;a-=a&-a)s+=bit[a],s%=mod;return s;}
  void clear(){bit.assign(n+1,0);}
};

int a[mn],o[mn];
ll lef[mn], rig[mn], bad[mn];

void solve() {
  int n;
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  iota(o,o+mn,0);
  sort(o,o+n, [](int i, int j){
    if(a[i] == a[j])return i > j;
    return a[i] < a[j];
  });
  for(int i=0;i<n;i++)a[o[i]] = i;
  //for(int i=0;i<n;i++)//cerr<<a[i]<<" ";
  //cerr<<endl;
  BIT bit(n+2);
  bit.upd(-1,1);
  for(int i=0;i<n;i++){
    lef[i] = bit.qry(a[i]-1);
    bit.upd(a[i],lef[i]);
    //cerr<< lef[i] << " ";
  }
  //cerr << endl;
  bit.clear();
  bit.upd(n,1);
  for(int i=n-1;i>=0;i--){
    rig[i] = (bit.qry(n)-bit.qry(a[i]))%mod;
    bit.upd(a[i],rig[i]);
  }
  bit.clear();
  int lv = -1;
  for(int i=n-1;i>=0;i--){
    if(a[i]<=lv)continue;
    vi vals;
    for(int j=lv+1;j<=a[i];j++)if(o[j]<=i)vals.push_back(o[j]);
    sort(all(vals),greater<int>());
    BIT bit(vals.size()+2);
    bad[i] = 1;
    bit.upd(vals.size()-1,1);
    for(int j:vals)if(j!=vals[0]){
      bad[j] = (bit.qry(vals.size())-bit.qry(a[j]-lv-1))%mod;
      bit.upd(a[j]-lv-1,bad[j]);
    }
    lv=a[i];
  }
  //for(int i=0;i<n;i++)//cerr<< rig[i] << " ";
  //cerr << endl;
  //for(int i=0;i<n;i++)//cerr<< bad[i] << " ";
  //cerr << endl;
  ll ans = 0;
  for(int i=0;i<n;i++){
    ans += lef[i]*(rig[i]-bad[i]),ans%=mod;
  }
  if(ans<0)ans+=mod;
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