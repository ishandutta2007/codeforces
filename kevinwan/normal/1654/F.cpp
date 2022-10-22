#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
const int mn = 2e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 1e9+7;


vi order(const string &s) {
  vi o(s.size()), ro(s.size());
  iota(all(o), 0);
  sort(all(o), [&](int i, int j) {
    return s[i] < s[j];
  });
  rep(i,0,sz(s)) {
    if(i>0&&s[o[i]]==s[o[i-1]]) {
      ro[o[i]] = ro[o[i-1]];
    } else {
      ro[o[i]] = i;
    }
  }
  for(int k=1;k<sz(s);k<<=1){
    iota(all(o), 0);
    sort(all(o), [&](int i, int j) {
      return tie(ro[i],ro[i^k]) < tie(ro[j],ro[j^k]);
    });
    vi nro(s.size());
    rep(i,0,sz(s)) {
      if(i>0&&tie(ro[o[i]], ro[o[i]^k])==tie(ro[o[i-1]], ro[o[i-1]^k])) {
        nro[o[i]] = nro[o[i-1]];
      }
      else {
        nro[o[i]] = i;
      }
    }
    ro = move(nro);
  }
  return o;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k = order(s)[0];
  for(int i=0;i<sz(s);i++) printf("%c", s[i^k]);
  printf("\n");
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  solve();

}