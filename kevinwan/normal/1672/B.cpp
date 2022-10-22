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

int a[mn];

void solve() {
  string s;
  cin >> s;
  int ct=0;
  bool fail=0;
  for(char c:s){
    if(c=='A')ct++;
    else ct--;
    if(ct<0){
      fail=1;
      break;
    }
  }
  if(s.back()=='A')fail=1;
  printf("%s\n",fail?"NO":"YES");
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