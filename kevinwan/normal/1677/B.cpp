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

int a[mn],pa[mn],rans[mn],cans[mn];
int cs[mn];

void solve(){
  int n,m;
  cin >> n >> m;
  rep(i,0,n*m)a[i]=pa[i]=rans[i]=cans[i]=cs[i]=0;
  string s;
  cin >> s;
  rep(i,0,n*m)a[i]=s[i]-'0';
  pa[0]=a[0];
  rep(i,1,n*m)pa[i] = pa[i-1] + a[i];
  rep(i,0,n*m){
    if(i<m)rans[i]=(pa[i]>0);
    else rans[i]=(pa[i]-pa[i-m]>0)+rans[i-m];
  }
  int cur=0;
  rep(i,0,n*m){
    if(cs[i%m]==0&&a[i]==1){
      cs[i%m]=1;
      cur++;
    }
    cans[i]=cur;
  }
  rep(i,0,n*m)printf("%d ",rans[i]+cans[i]);
  printf("\n");
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