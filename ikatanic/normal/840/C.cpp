#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int mod = 1e9 + 7;
const int MAX = 333;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

bool sq(llint x) {
  llint lo = 0, hi = 1e9;
  while (lo < hi) {
    llint mid = (lo + hi) / 2;
    if (mid * mid < x) lo = mid + 1;
    else hi = mid;
  }
  return lo*lo == x;
}

int fact[MAX];
int C[MAX][MAX];

int count(vector<int> a) {
  vector<int> f = {1};
  REP(j, (int)a.size()) {
    int sz = f.size();
    vector<int> nf(sz + a[j], 0);
    
    for (int k = 1; k <= a[j]; ++k) {
      int ways = C[a[j] - 1][k - 1];
      for (int i = 0; i < sz; ++i) {
        int nways = mul(ways, C[i + k][k]);
        nf[i + k] = add(nf[i + k], mul(f[i], nways));
      }
    }
    f = nf;
  }
  int ans = 0;
  REP(i, (int)f.size()) {
    if (((int)f.size() - i - 1) % 2) {
      ans = sub(ans, f[i]);
    } else {
      ans = add(ans, f[i]);
    }
  }
  return ans;
}

int main(void) {
  fact[0] = 1;
  FOR(i, 1, MAX) fact[i] = mul(fact[i-1], i);

  REP(i, MAX) {
    C[i][0] = 1;
    FOR(j, 1, i+1) C[i][j] = add(C[i-1][j-1], C[i-1][j]);
  }
  
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  REP(i, n) scanf("%d", &a[i]);

  vector<int> x;
  vector<bool> done(n, false);
  REP(i, n) {
    if (!done[i]) {
      int cnt = 0;
      REP(j, n)
        if (sq(a[i] * 1LL * a[j])) {
          assert(!done[j]);
          done[j] = true;
          cnt++;
        }
      x.push_back(cnt);
    }
  }    
      
  llint ans = count(x);
  for (int v: x) ans = mul(ans, fact[v]);

  printf("%lld\n", ans);
  return 0;
}