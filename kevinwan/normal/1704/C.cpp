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
void solve() {
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++)cin>>a[i];
  sort(a,a+m);
  vll v;
  for(int i=0;i<m-1;i++)v.push_back(a[i+1]-a[i]-1);
  v.push_back(a[0]+n-a[m-1]-1);
  sort(all(v),greater<ll>());

  int ans=0;
  for(int i=0;i<m;i++){
    int rem=v[i]-4*i;
    if(rem<=0){
      break;
    }
    ans+=max(1,rem-1);
  }
  printf("%d\n",n-ans);
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