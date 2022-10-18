#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int solve_max(vector<int>& c, int k) {
  int K = k;
  int N = accumulate(c.begin(), c.end(), 0);
  for (int x: c) {
    k = max(0, k - x/2);
  }
  return 2*(K-k) + min(k, N-2*(K-k));
}

const int MAX = 1e6 + 10;
const int inf = 1e9;

int solve_min(vector<int>& c, int k) {
  int n = *max_element(c.begin(), c.end())+1;
  vector<int> f(n);
  for (int x: c) f[x]++;

  bitset<MAX> can;
  can.set(0);

  vector<int> need(k+1);
  
  REP(i, n) {
    if (f[i] > 32) {
      REP(j, k+1) {
        if (can[j]) {
          need[j] = 0;
        } else {
          if (j-i >= 0) {
            need[j] = need[j-i] + 1;
          } else {
            need[j] = inf;
          }
          if (need[j] <= f[i]) can[j] = 1;
        }
      }
    } else {
      REP(j, f[i]) {
        can |= can << i;
      }
    }
  }
  return can[k] ? k : k+1;
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);

  vector<int> p(n);
  REP(i, n) {
    scanf("%d", &p[i]);
    --p[i];
  }

  vector<int> c;
  vector<bool> bio(n);
  REP(i, n) {
    if (!bio[i]) {
      int cnt = 0;
      int x = i;
      while (!bio[x]) {
        bio[x] = true;
        x = p[x];
        cnt++;
      }
      c.push_back(cnt);
    }
  }

  printf("%d %d\n", solve_min(c, k), solve_max(c, k));
  return 0;
}