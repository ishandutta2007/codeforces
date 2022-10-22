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

pll day[mn];
ll h[mn];
void solve() {
  ll n,m;
  cin >> n >> m;
  vector<pll> v;
  for(int i=0;i<n;i++){
    ll a,h;
    cin >> a >> h;
    day[i]={a,h};
    v.emplace_back(a-h,1);
    v.emplace_back(a+h,1);
    v.emplace_back(a,-2);
  }
  sort(all(v));
  ll sl=0;
  for(int i=0;i<v.size();i++) {
    if(i)h[i]=h[i-1]+(v[i].first-v[i-1].first)*sl;
    sl+=v[i].second;
  }
  ll mxx=-inf,myy=-inf;
  for(int i=0;i<v.size();i++){
    if(h[i]<=m)continue;
    ll x=v[i].first+h[i]-m,y=-v[i].first+h[i]-m;
    mxx=max(mxx,x),myy=max(myy,y);
  }
  string ans(n,'0');
  for(int i=0;i<n;i++){
    ans[i]='0'+(day[i].first+day[i].second>=mxx&&-day[i].first+day[i].second>=myy);
  }
  printf("%s\n",ans.c_str());
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