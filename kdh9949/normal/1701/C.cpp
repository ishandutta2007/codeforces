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


int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(t);
  while(t--) {
    ints(n, m);
    vint a(m);
    for(int &x : a) cin >> x;
    int L = 1, R = 2 * m;
    const auto f = [&](int k) {
      vint cnt(n + 1);
      int lft = 0;
      for(int &x : a) {
        if(cnt[x] < k) cnt[x]++;
        else lft++;
      }
      for(int i = 1; i <= n; i++) {
        lft -= (k - cnt[i]) / 2;
        if(lft <= 0) return 1;
      }
      return 0;
    };
    while(L < R) {
      int M = (L + R) / 2;
      if(f(M)) R = M;
      else L = M + 1;
    }
    cout << L << '\n';
  }

  return 0;
}