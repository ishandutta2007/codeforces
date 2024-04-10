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
const int mn = 4e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;

lll lllgcd(lll a, lll b) {
  while(b) a%=b, swap(a,b);
  return a;
}

struct seg {
  vector<lll> v;
  int n;
  seg(int n): v(n*2, 0), n(n) {}
  void upd(int x, lll val) {
    v[x += n] = val;
    for (x >>= 1; x; x >>= 1) v[x] = lllgcd(v[x<<1], v[(x<<1)|1]);
  }
};

lll scan() {
  lll x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}



void print(lll x) {
  if(x == 0) printf(" ");
  else {
    vector<char> v;
    while(x) v.push_back(x%10 + '0'), x/=10;
    for(int i = sz(v)-1; i >= 0; --i) putchar(v[i]);
  }
}

void solve() {
  int n,m;
  n = scan(), m = scan();
  vector<lll> a(n),b(m);
  vector<seg> aseg(n,seg(m)),bseg(m,seg(n));
  rep(i,0,n) a[i] = scan();
  rep(i,0,m) b[i] = scan();
  vector<pii> bad;
  rep(i,0,n) {
    rep(j,0,m) aseg[i].upd(j, a[i]/lllgcd(a[i], b[j]));
    if(aseg[i].v[1] != 1) bad.emplace_back(i,0);
  }
  rep(i,0,m) {
    rep(j,0,n) bseg[i].upd(j, b[i]/lllgcd(a[j], b[i]));
    if(bseg[i].v[1] != 1) bad.emplace_back(i,1);
  }
  while(bad.size()) {
    while(bad.size()) {
      auto [i,t] = bad.back();
      bad.pop_back();
      if(t == 0) {
        a[i] = 0;
        rep(j,0,m) bseg[j].upd(i, 0);
      }
      else {
        b[i] = 0;
        rep(j,0,n) aseg[j].upd(i, 0);
      }
    }
    rep(i,0,n) if(a[i]!=0 && aseg[i].v[1] != 1) bad.emplace_back(i,0);
    rep(i,0,m) if(b[i]!=0 && bseg[i].v[1] != 1) bad.emplace_back(i,1);
  }
  vi va, vb;
  rep(i,0,n) if(a[i]!=0) va.push_back(i);
  rep(i,0,m) if(b[i]!=0) vb.push_back(i);
  if(va.size() == 0 || vb.size() == 0) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  printf("%d %d\n", sz(va), sz(vb));
  rep(i,0,sz(va)) print(a[va[i]]), printf(" ");
  printf("\n");
  rep(i,0,sz(vb)) print(b[vb[i]]), printf(" ");
  printf("\n");
}

int main(){
  //cin.tie(0);
  //cin.sync_with_stdio(false);
  int tc = scan();
  while(tc--)solve();
}