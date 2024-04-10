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
const int mn = 5e3+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;

ll numl[mn], numr[mn];
int a[mn];

void solve(){
  int n;
  cin >> n;
  rep(i,0,n)cin>>a[i];
  ll ans=0;
  rep(i,1,n-1){
    rep(j,0,n+1)numr[j]=0;
    rep(j,i+1,n)numr[a[j]]++;
    rep(j,1,n+1)numr[j]+=numr[j-1];
    ll sub=0;
    for(int j=i-1;j>=0;j--){
      if(a[j]<a[i])ans+=sub;
      sub+=numr[a[j]];
      //cerr << i << " " << j << " " << sub << endl;
    }
  }
  printf("%lld\n",ans);
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