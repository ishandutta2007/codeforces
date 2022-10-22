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
 
int a[mn],b[mn];
 
void solve() {
  int n;
  cin >> n;
  vi f(n+1);
  vi nxt(n+1);
  rep(i,1,n+1) cin >> a[i],f[a[i]]++;
  int mo=0;
  for(int i=1;i<=n;i++)if(f[i]>f[mo])mo=i;
  vi o(n+1);
  iota(all(o),0);
  sort(o.begin()+1,o.end(), [&](int i,int j){
    if(f[a[i]]!=f[a[j]])return f[a[i]]>f[a[j]];
    return a[i]<a[j];
  });
  vi ro(n+1);
  for(int i=1;i<=n;i++){
    nxt[o[i]]=o[(i+f[mo]-1)%n+1];
  }
  for(int i=1;i<=n;i++)b[nxt[i]]=a[i];
  for(int i=1;i<=n;i++)printf("%d ",b[i]);
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