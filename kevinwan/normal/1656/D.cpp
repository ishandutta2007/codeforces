#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
  ll n;
  cin >> n;
  ll p = 1;
  while(n%2==0)n/=2,p*=2;
  if(n==1)printf("-1\n");
  else if(n<2*p)printf("%lld\n", n);
  else printf("%lld\n", 2*p);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int tc;
  cin>>tc;
  while(tc--){
    solve();
  }
}