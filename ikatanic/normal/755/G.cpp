#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int mod = 998244353; // 2 ^ 23 * 17 * 7
int g = 0; // !

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}
  
inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}
  
inline int mul(int a, int b) {
  return llint(a)*b % mod;
}


namespace NTT {
  int g = 0; // !

  int powmod(int a, int b) {
    if (b == 0) return 1;
    if (b&1) return mul(a, powmod(a, b-1));
    return powmod(mul(a, a), b/2);
  }

  void findPrimitiveRoot() {
    if (g) return;

    vector<int> d;
    for (int i = 2; i*i <= mod-1; ++i)
      if ((mod-1) % i == 0) d.push_back(i), d.push_back((mod-1)/i);
    for (g = 2; ; g++) {
      bool ok = true;
      for (int x: d) ok &= powmod(g, x) != 1;
      if (ok) break;
    }
  }
  
  void transform(int* a, int* z, int* omega, int m, int N) {
    if (m == 1) {
      z[0] = a[0];
    } else {
      int s = N/m;
      m /= 2;
 
      transform(a, z, omega, m, N);
      transform(a+s, z+m, omega, m, N);
 
      REP(i, m) {
        int c = mul(omega[s*i], z[m+i]);
        z[m+i] = sub(z[i], c);
        z[i] = add(z[i], c);
      }
    }
  }

  vector<int> fft(vector<int>& a) {
    findPrimitiveRoot();

    int N = a.size();
    int w = powmod(g, (mod-1) / N);
    vector<int> omega(N);
    omega[0] = 1;
    FOR(i, 1, N) omega[i] = mul(omega[i-1], w);

    vector<int> z(N);
    transform(a.data(), z.data(), omega.data(), N, N);
    return z;
  }
  
  vector<int> ifft(vector<int>& a) {
    findPrimitiveRoot();

    int N = a.size();
    int wi = powmod(powmod(g, (mod-1)/N), mod-2);
    vector<int> omega(N);
    omega[0] = 1;
    FOR(i, 1, N) omega[i] = mul(omega[i-1], wi);

    vector<int> z(N);
    transform(a.data(), z.data(), omega.data(), N, N);
    
    int invN = powmod(N, mod - 2);
    REP(i, N) z[i] = mul(z[i], invN);
    return z;
  }
  
  vector<int> mult(vector<int> a, vector<int> b) {
    int N = a.size() + b.size();
    while (N & (N-1)) ++N;

    a.resize(N, 0);
    b.resize(N, 0);

    vector<int> ta = fft(a);
    vector<int> tb = fft(b);
    REP(i, N) ta[i] = mul(ta[i], tb[i]);
    return ifft(ta);
  }
};

const int MAXK = 1<<16;

const int Q = 100;

int f[Q][Q];

map<int, vector<int>> M[2][2];
set<int> bio;

void solve(int n, int k) {
  if (bio.count(n)) return;

  bio.insert(n);

  if (n < Q) {
    REP(a, 2) REP(b, 2) {
      M[a][b][n].resize(min(n+1, k+1), 0);
      REP(l, min(k+1, n+1)) {
        if (a+b <= n) {
          M[a][b][n][l] = f[n-a-b][l];
        }
      }
    }
    return;
  }
  
  
  int l = n/2, r = n - l;

  solve(l, k);
  solve(r, k);

  REP(a, 2) REP(b, 2) M[a][b][n].resize(min(k+1, n+1));

  int L = M[0][0][l].size() + M[0][0][r].size();
  while (L & (L-1)) L++;
  
  vector<int> tl[2][2], tr[2][2];
  REP(a, 2) REP(b, 2) {
    if (a == 1 && b == 0) continue;
    
    tl[a][b] = M[a][b][l];
    tl[a][b].resize(L);
    tl[a][b] = NTT::fft(tl[a][b]);

    if (l == r) {
      tr[a][b] = tl[a][b];
    } else {
      tr[a][b] = M[a][b][r];
      tr[a][b].resize(L);
      tr[a][b] = NTT::fft(tr[a][b]);
    }
  }

  REP(a, 2) REP(b, 2) REP(c, 2) {
    if (a == 1 && c == 0) continue;
    
    auto& C = M[a][c][n];

    auto& A = a < b ? tl[a][b] : tl[b][a];
    auto& B = b < c ? tr[b][c] : tr[c][b];
    
    vector<int> tmp(L);
    REP(i, L) tmp[i] = mul(A[i], B[i]);

    tmp = NTT::ifft(tmp);
    REP(i, min(n+1, k+1)) {
      int j = i + b;
      if (tmp[i] && j <= k) {
        assert(j < min(k+1, n+1));
        C[j] = add(C[j], tmp[i]);
      }
    }
  }
}

int main(void) {
  f[0][0] = 1;
  FOR(n, 1, Q) REP(k, Q) {
    f[n][k] = f[n-1][k];
    if (k > 0) f[n][k] = add(f[n][k], f[n-1][k-1]);
    if (k > 0 && n > 1) f[n][k] = add(f[n][k], f[n-2][k-1]);
  }

  int n, k;
  scanf("%d %d", &n, &k);
  
  solve(n, k);
  vector<int> ans = M[0][0][n];

  while ((int)ans.size() <= k) ans.push_back(0);
  REP(i, k) printf("%d ", ans[i+1]);
  printf("\n");
  return 0;
}