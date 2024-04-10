#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

ll ans = 0;

constexpr int K = 450;
struct Bucket {
  ll ofs, has, tot, c[K], h[K];
  void u(int s, int e, int v) {
    if(s == 0 && e == K - 1) {
      ofs += v;
      if(v > 0) ans += tot << 1;
      tot += v * has;
      if(v < 0) ans -= tot << 1;
      return;
    }
    for(int i = s; i <= e; i++) {
      if(h[i] && v > 0) ans += (c[i] + ofs) << 1; 
      c[i] += v;
      if(h[i]) tot += v;
      if(h[i] && v < 0) ans -= (c[i] + ofs) << 1;
    }
  }
  void tog(int x) {
    ll cc = c[x] + ofs;
    if(h[x]) { ans -= cc * (cc - 1); tot -= cc; has--; }
    else { ans += cc * (cc - 1); tot += cc; has++; }
    h[x] ^= 1;
  }
} B[K];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(q, k);
  while(q--) {
    ints(x);
    if(!B[x / K].h[x % K]) {
      //for(int i = max(x - k, 1); i < x; i++) ans += (h[i] & c[i]++) << 1;
      for(int i = 0; i < K; i++)
        B[i].u(max(0, x - k - i * K), min(K, x - i * K) - 1, 1);
      B[x / K].tog(x % K);
    } else {
      //for(int i = max(x - k, 1); i < x; i++) ans -= (h[i] & --c[i]) << 1;
      for(int i = 0; i < K; i++)
        B[i].u(max(0, x - k - i * K), min(K, x - i * K) - 1, -1);
      B[x / K].tog(x % K);
    }
    cout << (ans >> 1) << '\n';
  }

  return 0;
}