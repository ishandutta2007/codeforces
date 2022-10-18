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

const int M = 100100;
const int offset = 1<<14;
const int inf = 1e9;

vector<int> v[M];
vector<int> e[M];
int T[2*offset];
int S[2*offset];

int query(int i, int k) {
  if (k == 0) return 0;
  if (i >= offset) return k*(i-offset);
  if (T[i*2] >= k) return query(i*2, k);
  return query(i*2+1, k - T[i*2]) + S[i*2];
}

void kill(int x) {
  x += offset;
  T[x]--;
  S[x] -= (x-offset);
  for (x /= 2; x; x /= 2) {
    T[x] = T[x*2] + T[x*2+1];
    S[x] = S[x*2] + S[x*2+1];
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  int rem = 0;
  REP(i, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    if (a) {
      T[offset + b]++;
      S[offset + b] += b;
      rem++;
    }
  }

  int cnt = (int)v[0].size();
  for (int i = offset-1; i > 0; --i) {
    T[i] = T[i*2] + T[i*2+1];
    S[i] = S[i*2] + S[i*2+1];
  }

  FOR(i, 1, M)
    if (v[i].size()) {
      e[v[i].size()].push_back(i);
      sort(v[i].begin(), v[i].end(), greater<int>());
    }

  int ans = inf;
  int cost = 0;

  static vector<int> active;
  for (int g = M-1; g > 0; --g) {
    // pobjedujem s g glasova
    for (int x: e[g]) active.push_back(x);

    // svim aktivnima uzmi jedan glas
    for (int x: active) {
      cnt++;
      cost += v[x].back();
      kill(v[x].back());
      rem--;
      v[x].pop_back();
    }

    // ako jos treba uzmi najjeftinije preostalo
    if (cnt < g) {
      if (g-cnt <= rem) ans = min(ans, cost + query(1, g-cnt));
    } else
      ans = min(ans, cost);
  }

  printf("%d\n", ans);
  
  return 0;
}