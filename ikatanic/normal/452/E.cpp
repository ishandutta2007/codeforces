#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

// pozvati build(char *s, int len)
// nakon toga: 
//     A[i] -> indeks i-tog sufixa u sortiranom nizu sufiksa
//     lcp[i] -> lcp sufiksa A[i] i A[i-1], lcp[0] = nedefinirano

namespace SuffixArray {
  const int MAXN = 300010;

  int lcp[MAXN], A[MAXN];

  void build(char *s, int n) {
    static int tmp[MAXN], bc[MAXN]; // bucket id
    for (int i = 0; i < n; ++i)
      A[i] = i, bc[i] = s[i];

    for (int T = 1; ; T *= 2) {
      auto cmp = [&s, &n, &T] (const int &a, const int &b) {
        if (bc[a] != bc[b]) return bc[a] < bc[b];
        return (a+T >= n || b+T >= n) ? a > b : bc[a+T] < bc[b+T];
      };
      sort(A, A + n, cmp);
      tmp[A[0]] = 0;
      for (int i = 1; i < n; ++i)
        tmp[A[i]] = tmp[A[i-1]] + cmp(A[i-1], A[i]);
      for (int i = 0; i < n; ++i)
        bc[i] = tmp[i];
      if (bc[A[n-1]] == n-1) break;
    }
    
    lcp[0] = 0;
    int h = 0;
    for (int i = 0; i < n; ++i)
      if (bc[i] > 0) {
        int j = A[ bc[i]-1 ];
        while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
        lcp[bc[i]] = h;
        if (h > 0) --h;
      }
  }
};

typedef long long llint;
typedef pair<int, int> par;
#define h first
#define i second

const int MAXN = 300300;
const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

char a[3][MAXN];
int w[MAXN], g[MAXN];
int l[3];

int ans[MAXN];
char s[MAXN];

vector<int> e[MAXN];
vector<int> v[MAXN];
vector<int> p[MAXN];

int c[MAXN][3];

int main(void) {
  int n = 0;
  REP(i, 3) {
    scanf("%s", a[i]);
    l[i] = strlen(a[i]);
    REP(j, l[i]) {
      w[n] = i;
      s[n++] = a[i][j];
    }
  }
  
  SuffixArray::build(s, n);
  int *lcp = SuffixArray::lcp;
  int *A = SuffixArray::A;

  FOR(i, 1, n)
    e[lcp[i]].push_back(i);
  
  REP(x, n) {
    if (w[x] == 0) p[l[0]-x].push_back(x); else
      if (w[x] == 1) p[l[1]+l[0]-x].push_back(x);
      else p[n-x].push_back(x);
  }

  REP(i, n) {
    g[i] = i;
    v[i] = {i};
  }
  
  auto count = [] (int i) {
    int ans = 1;
    REP(j, 3) ans = mul(ans, c[i][j]);
    return ans;
  };

  int cur = 0;
  for (int i = n; i >= 0; --i) {
    for (int j: e[i]) {
      int x = A[j], y = A[j-1];
      x = g[x], y = g[y];
      assert(x != y);
      
      if (v[x].size() < v[y].size()) swap(x, y);
      
      cur = sub(cur, count(x));
      cur = sub(cur, count(y));


      for (int py: v[y]) {
        v[x].push_back(py);
        g[py] = x;
      }
      REP(k, 3) c[x][k] += c[y][k];
      v[y].clear();

      cur = add(cur, count(x));
    }
    
    for (int j: p[i]) {
      cur = sub(cur, count(g[j]));
      c[g[j]][w[j]]++;
      cur = add(cur, count(g[j]));
    }

    ans[i] = cur;
  }

  int k = *min_element(l, l + 3);
  REP(i, k) printf("%d ", ans[i+1]);
  printf("\n");
  return 0;
}