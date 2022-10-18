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

llint gcd(llint a, llint b) {
  return !b ? a : gcd(b, a%b);
}

struct frac {
  llint a, b;
  frac (llint _a = 0, llint _b = 1) {
    if (_b < 0) {
      _b *= -1;
      _a *= -1;
    }
    llint g = gcd(abs(_a), _b);
    a = _a/g, b = _b/g;
  }

  friend frac operator + (const frac &a, const frac &b) {
    return frac(llint(a.a)*b.b + llint(a.b)*b.a, llint(a.b)*b.b);
  }
  friend frac operator * (const frac &a, const frac &b) {
    return frac(llint(a.a)*b.a, llint(a.b)*b.b);
  }
  friend frac operator / (const frac &a, const frac &b) {
    return frac(llint(a.a)*b.b, llint(a.b)*b.a);
  }
  friend frac operator - (const frac &a, const frac &b) {
    return frac(llint(a.a)*b.b - llint(a.b)*b.a, llint(a.b)*b.b);
  }
  friend bool operator < (const frac &a, const frac &b) {
    return llint(a.a)*b.b < llint(b.a)*a.b;
  }
  friend bool operator == (const frac &a, const frac &b) {
    return llint(a.a)*b.b == llint(b.a)*a.b;
  }
};


const int MAX = 101000;

int L[MAX];

int sum(int x) {
  int r = 0;
  for (++x; x; x -= x&-x)
    r += L[x];
  return r;
}

void add(int x, int v) {
  for (++x; x < MAX; x += x&-x)
    L[x] += v;
}

int main(void) {
  int N, W;
  scanf("%d %d", &N, &W);

  typedef pair<frac, frac> plane;
  vector<plane> a;
  vector<frac> values;
  REP(i, N) {
    int x, v;
    scanf("%d %d", &x, &v);
    frac f1(x, v - W);
    frac f2(x, v + W);

    values.push_back(f2);
    a.push_back({f1, f2});
  }

  sort(values.begin(), values.end());
  sort(a.begin(), a.end(), [&] (const plane& a, const plane& b) {
    if (a.first == b.first) {
      return b.second < a.second;
    } else {
      return a.first < b.first;
    }
    });

  llint ret = 0;
  for (int i = N-1; i >= 0; --i) {
    int y = lower_bound(values.begin(), values.end(), a[i].second) - values.begin();

    ret += sum(y);
    add(y, 1);
  }
  printf("%lld\n", ret);
  return 0;
}