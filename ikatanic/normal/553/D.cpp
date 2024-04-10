#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a%b);
}

struct frac {
  int a, b;
  friend bool operator < (const frac &a, const frac &b) {
    return llint(a.a)*b.b < llint(b.a)*a.b;
  }
  friend bool operator == (const frac &a, const frac &b) {
    return !(a < b) && !(b < a);
  }
};

vector<int> E[MAX];
frac score[MAX];
int deg[MAX];
bool f[MAX], dead[MAX];

queue<int> Q;
vector<int> v, ans;
vector<frac> w;
int n, m, k;

bool test(frac M) {
  while (!Q.empty()) Q.pop();
  REP(i, n) dead[i] = f[i];
  REP(i, n) {
    if (dead[i]) continue;
    score[i] = {deg[i], deg[i]};

    for (int j: E[i])
      score[i].a -= f[j];
    if (score[i] < M) Q.push(i), dead[i] = true;
  }

  while (!Q.empty()) {
    int x = Q.front(); Q.pop();

    for (int y: E[x])
      if (!dead[y]) {
        score[y].a--;
        if (score[y] < M) Q.push(y), dead[y] = true;
      }
  }

  ans.clear();
  REP(i, n)
    if (!dead[i]) ans.push_back(i);
  return ans.size() != 0;
}

int main(void) {
  scanf("%d %d %d", &n, &m, &k);
  
  REP(i, k) {
    int x;
    scanf("%d", &x); --x;
    f[x] = true;
    v.push_back(x);
  }
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  REP(i, n) {
    deg[i] = E[i].size();
    assert(deg[i] > 0);
    
    for (int j = 0; j <= deg[i]; ++j) {
      int A = j, B = deg[i];
      int g = gcd(A, B);
      A /= g, B /= g;
      w.push_back({A, B});
    }
  }
   
  sort(w.begin(), w.end());
  w.erase(unique(w.begin(), w.end()), w.end());

  int lo = 0, hi = (int)w.size() - 1;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (test(w[mid])) lo = mid; else
      hi = mid - 1;
  }
  
  test(w[lo]);

  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d ", x+1);
  printf("\n");
  return 0;
}