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
  string s;
  cin >> s;
  int n = sz(s);
  int num=1;
  bool fail=0;
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1])num++;
    else {
      if(num==1)fail=1;
      num=1;
    }
  }
  if(num==1)fail=1;
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