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
  int n,m;
  cin >> n>> m;
  string a,b;
  cin >> a>>b;
  int at=0;
  for(int i=0;i<n-(m-1);i++){
    if(at<1&&a[i]==b[at])at++;
  }
  for(int i=0;i<m-1;i++){
    if(a[n-1-i]!=b[m-1-i])at=0;
  }
  printf("%s\n",at==1?"YES":"NO");
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