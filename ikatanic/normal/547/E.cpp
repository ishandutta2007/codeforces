#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXBUFF = 1<<20;

namespace IO {
  char buffer[MAXBUFF], *p = buffer+MAXBUFF;
  
  inline char read_char() {
    if (p == buffer+MAXBUFF) {
      fread(buffer, 1, MAXBUFF, stdin);
      p = buffer;
    }
    return *p++;
  }
  
  inline int read_int() {
    char c;
    while (!isdigit(c = read_char()));
    int ret = c-'0';
    while (isdigit(c = read_char())) ret = ret*10 + c-'0';
    return ret;
  }
};

const int MAX = 550000;
const int off = 1<<19;

namespace SuffixArray {
  const int MAXN = 500030;

  int lcp[MAXN], A[MAXN];
  
  void build(char *s, int n) {
    static int tmp[MAXN], bc[MAXN];
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

struct Loga {
  int L[MAX];
  
  void add(int x, int v) {
    for (++x; x < MAX; x += x&-x)
      L[x] += v;
  }

  int sum(int x) {
    int r = 0;
    for (++x; x; x -= x&-x)
      r += L[x];
    return r;
  }
} L;

struct Query {
  int l, r, i;
};

struct Query2 {
  int l, r, i, k;
};
vector<Query2> Q[MAX];

vector<Query> V[MAX];

int ans[MAX];
int who[MAX];

int len[MAX];
char buff[MAX];
char *s[MAX];
int id[MAX];

int T2[2*off];

int getmin(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return MAX;
  if (lo >= a && hi <= b) return T2[i];
  return min(getmin(i*2, lo, (lo+hi)/2, a, b), getmin(i*2+1, (lo+hi)/2, hi, a, b));
}
  
int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  
  char *cur = buff;
  REP(i, n) {
    scanf("%s", cur);
    s[i] = cur;
    len[i] = strlen(s[i]);
    cur += len[i] + 1;
  }
  
  int total = cur - buff;
  SuffixArray::build(buff, total);

  REP(i, q) {
    int l, r, k;
    //    scanf("%d %d %d", &l, &r, &k); --l, --r, --k;
    l = IO::read_int();
    r = IO::read_int();
    k = IO::read_int();
    --l, --r, --k;
    V[k].push_back({l, r, i});
  }

  REP(i, total) id[ SuffixArray::A[i] ] = i;
  REP(i, n) REP(j, len[i]) who[ id[s[i] + j - buff] ] = i;

  REP(i, total) T2[off + i] = SuffixArray::lcp[i];
  for (int i = off-1; i > 0; --i)
    T2[i] = min(T2[i*2], T2[i*2+1]);

  REP(i, n) {
    int idx = id[s[i] - buff];
    
    int lo = 0, hi = idx + 1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (getmin(1, 0, off, mid, idx + 1) >= len[i]) hi = mid; else
        lo = mid + 1;
    }
    int left = lo - 1;

    lo = idx, hi = total;
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (getmin(1, 0, off, idx + 1, mid + 1) >= len[i]) lo = mid; else
        hi = mid - 1;
    }
    int right = lo;

    for (auto &q: V[i]) {
      if (left > 0) Q[left-1].push_back({q.l, q.r, q.i, -1});
      Q[right].push_back({q.l, q.r, q.i, +1});
    }
  }
  
  REP(i, total) {
    L.add(who[i], +1);
    for (auto &q: Q[i])
      ans[q.i] += q.k * (L.sum(q.r) - L.sum(q.l - 1));
  }

  REP(i, q) printf("%d\n", ans[i]);
  return 0;
}