#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 500500;
const int off = 500010;

namespace SuffixArray {
  int lcp[MAX], A[MAX];
  
  void build(char *s, int n) {
    static int tmp[MAX], bc[MAX];
    REP(i, n) A[i] = i, bc[i] = s[i];

    for (int T = 1; ; T *= 2) {
      auto cmp = [&s, &T, &n] (const int &a, const int &b) {
	if (bc[a] != bc[b]) return bc[a] < bc[b];
	if (a+T >= n || b+T >= n) return a > b;
	return bc[a+T] < bc[b+T];
      };
      sort(A, A + n, cmp);
      tmp[A[0]] = 0;
      FOR(i, 1, n) tmp[A[i]] = tmp[A[i-1]] + cmp(A[i-1], A[i]);
      REP(i, n) bc[i] = tmp[i];
      if (bc[A[n-1]] == n-1) break;
    }

    lcp[0] = 0;
    int h = 0;
    REP(i, n)
      if (bc[i] > 0) {
	int j = A[ bc[i]-1 ];
	while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
	lcp[bc[i]] = h;
	if (h > 0) --h;
      }
  }
};

int bal[MAX];
int p[MAX];
char s[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  SuffixArray::build(s, n);
  int* lcp = SuffixArray::lcp;
  int* A = SuffixArray::A;

  bal[0] = 0;
  REP(i, n) bal[i+1] = bal[i] + (s[i] == '(' ? +1 : -1);
  bal[n+1] = -2*n;

  static vector<int> v[2*MAX];
  REP(i, n+1) v[off + bal[i]].push_back(i);

  stack<int> S;
  S.push(n+1);
  for (int i = n; i >= 0; --i) {
    while (bal[i] <= bal[S.top()]) S.pop();
    p[i] = S.top() - 1;
    S.push(i);
  }

  llint ans = 0;
  REP(i, n) {
    int lo = A[i] + lcp[i] + 1;
    int hi = p[A[i]];
    if (lo <= hi) {
      auto& w = v[off + bal[A[i]]];
      ans += upper_bound(w.begin(), w.end(), hi) - lower_bound(w.begin(), w.end(), lo);
    }
  }

  printf("%lld\n", ans);
  return 0;
}