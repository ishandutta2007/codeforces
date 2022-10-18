#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const llint MAX = 3e18;

const int mod = 998244353;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }

inline int sub(int a, int b) { return a >= b ? a - b : a - b + mod; }

inline int mul(int a, int b) { return llint(a) * b % mod; }

llint is_pow(llint x, int k) {
  llint lo = 2, hi = llint(pow(MAX, 1.0 / k));
  while (lo < hi) {
    llint mid = (lo + hi) / 2;
    llint pw = 1;
    REP(i, k) pw *= mid;
    if (pw < x)
      lo = mid + 1;
    else
      hi = mid;
  }

  llint pw = 1;
  REP(i, k) pw *= lo;
  if (pw == x) {
    return lo;
  } else {
    return 0;
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  map<llint, int> primes;
  vector<llint> pqs;

  REP(i, n) {
    llint x;
    cin >> x;
    if (x == 1) continue;

    llint p;
    if ((p = is_pow(x, 4))) {
      primes[p] += 4;
    } else if ((p = is_pow(x, 3))) {
      primes[p] += 3;
    } else if ((p = is_pow(x, 2))) {
      primes[p] += 2;
    } else {
      pqs.push_back(x);
    }
  }

  int m = pqs.size();
  vector<llint> f(m, 0);
  REP(i, m) REP(j, i) {
    if (pqs[i] != pqs[j]) {
      llint p = __gcd<llint>(pqs[i], pqs[j]);
      if (p > 1) {
        f[i] = f[j] = p;
      }
    }
  }

  vector<llint> npqs;
  REP(i, m) {
    if (f[i]) {
      primes[f[i]]++;
      primes[pqs[i] / f[i]]++;
    } else {
      npqs.push_back(pqs[i]);
    }
  }
  pqs = npqs;

  vector<llint> all_primes;
  for (auto& p : primes) all_primes.push_back(p.first);

  for (int i = 0; i < (int)all_primes.size(); ++i) {
    llint p = all_primes[i];
    for (llint& pq : pqs) {
      if (pq % p == 0) {
        primes[p]++;
        llint q = pq / p;
        if (!primes.count(q)) {
          all_primes.push_back(q);
        }
        primes[q]++;
        pq = 1;
      }
    }
  }

  map<llint, int> pq_cnt;
  for (llint pq : pqs) {
    if (pq > 1) pq_cnt[pq]++;
  }

  int ret = 1;
  for (auto& pqc : pq_cnt) {
    ret = mul(ret, 1 + pqc.second);
    ret = mul(ret, 1 + pqc.second);
  }

  for (auto& p : primes) {
    ret = mul(ret, 1 + p.second);
  }

  cout << ret << "\n";
  return 0;
}