#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

vector<int> E[MAX];
vector<int> divs[MAX];

int f[MAX];
int a[MAX];
int phi[MAX];
int fact[MAX];
bool sqfree[MAX];

int sx[MAX]; // sum of phi(x) of subtree
int sdx[MAX]; // sum of phi(x)d(x) of subtree
int depth_off;
vector<int> vals; // i s.t. sx[i] != 0 or sdx[i] != 0

int sz[MAX];

void dfs_pre(int x, int dad) {
  sz[x] = divs[a[x]].size() + 1;
  for (int y: E[x]) {
    if (y != dad) {
      dfs_pre(y, x);
      sz[x] += sz[y];
    }
  }
}

void add_node(int x, int d, bool compute) {
  for (int div: divs[a[x]]) {
    if (compute) {
      f[div] = add(f[div], mul(sdx[div], phi[a[x]]));
      f[div] = add(f[div], mul(sx[div], mul(phi[a[x]], add(d, depth_off))));
    } else {
      if (sx[div] == 0 && sdx[div] == 0) {
        vals.push_back(div);
      }
      sx[div] = add(sx[div], phi[a[x]]);
      sdx[div] = add(sdx[div], mul(phi[a[x]], sub(d, depth_off)));
    }
  }
}

void dfs_add(int x, int dad, int depth, bool compute) {
  add_node(x, depth, compute);
  for (int y: E[x]) {
    if (y != dad) {
      dfs_add(y, x, depth + 1, compute);
    }
  }
}

void dfs(int x, int dad, bool keep) {
  int m = -1;
  for (int y: E[x]) {
    if (y != dad && (m == -1 || sz[y] > sz[m])) {
      m = y;
    }
  }

  for (int y: E[x]) {
    if (y != dad && y != m) {
      dfs(y, x, false);
    }
  }

  if (m != -1) {
    dfs(m, x, true);
  }

  depth_off++; 
  
  for (int y: E[x]) {
    if (y != dad && y != m) {
      dfs_add(y, x, 1, true);
      dfs_add(y, x, 1, false);
    }
  }
  add_node(x, 0, true);
  add_node(x, 0, false);
  
  if (!keep) {
    for (int val: vals) {
      sx[val] = sdx[val] = 0;
    }
    depth_off = 0;
    vals.clear();
  }
}

int main(void) {
  phi[1] = 1;
  sqfree[1] = true;
  for (int i = 2; i < MAX; ++i) {
    if (fact[i] == 0) {
      if (llint(i)*i < MAX)
        for (int j = i*i; j < MAX; j += i)
          fact[j] = i;
      fact[i] = i;
      sqfree[i] = true;
      phi[i] = i-1;
    } else {
      int x = i;
      while (x%fact[i] == 0) x /= fact[i];
      if (x == 1) phi[i] = fact[i] * phi[i / fact[i]]; else
        phi[i] = phi[x] * phi[i / x];

      sqfree[i] = sqfree[x] && (x * fact[i] == i);
    }
  }

  for (int i = 1; i < MAX; ++i) {
    if (sqfree[i]) {
      for (int j = i; j < MAX; j += i) {
        divs[j].push_back(i);
      }
    }
  }
  
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs_pre(0, -1);
  dfs(0, -1, false);
  
  int ret = 0;
  for (int i = n; i >= 1; --i) {
    if (sqfree[i]) {
      for (int k = 2; i*k <= n; ++k) {
        f[i] = sub(f[i], f[i * k]);
      }
      int w = mul(f[i], i);
      w = mul(w, powmod(phi[i], mod - 2));
      ret = add(ret, w);
    } else {
      f[i] = 0;
    }
  }

  ret = mul(ret, 2);
  ret = mul(ret, powmod(mul(n, n-1), mod - 2));
  printf("%d\n", ret);
  return 0;
}