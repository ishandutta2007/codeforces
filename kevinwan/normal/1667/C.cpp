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
const ll mod = 1e9+7;

void solve() {
  int n;
  cin >> n;
  if(n==1){printf("1\n1 1");return;}
  int k = (n+1)/3;
  vector<pii> v;
  for(int i=0;i<2*k-1;i++){
    v.emplace_back(1+i,1+(2*i)%(2*k-1));
  }
  for(int i=3*k;i<=n;i++)v.emplace_back(i,i);
  printf("%d\n", sz(v));
  for(auto [a,b]: v)printf("%d %d\n", a, b);
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc=1;
  //cin >> tc;
  while(tc--){
    solve();
  }
}