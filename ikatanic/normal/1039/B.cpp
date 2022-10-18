#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

bool ask(llint l, llint r) {
  cout << l << " " << r << "\n";
  cout.flush();

  string ans;
  cin >> ans;
  if (ans == "Bad") {
    exit(0);
  }

  if (ans == "Yes" && l == r) {
    exit(0);
  }

  return ans == "Yes";
}

int main(void) {
  ios_base::sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

  llint N, K;
  cin >> N >> K;
  uniform_int_distribution<int> ud(0, N);

  llint lo = 1, hi = N;
  while (true) {
    while (hi - lo > 60) {
      llint mid = (lo + hi) / 2;
      if (ask(mid, hi)) {
        lo = max(1LL, mid - K);
        hi = min(N, hi + K);
      } else {
        lo = max(1LL, lo - K);
        hi = min(N, mid - 1 + K);
      }
    }

    while (hi - lo <= 100) {
      llint x = uniform_int_distribution<llint>(lo, hi)(rng);
      ask(x, x);
      lo = max(1LL, lo - K);
      hi = min(N, hi + K);
    }
  }

  return 0;
}