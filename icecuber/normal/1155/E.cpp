#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e6+3;
ll A0[11][11], A[11][11], b0[11], b[11], x[11];

ll inv(ll a) {
  ll p = mod-2, r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

void solve(int n) {
  if (n == 0) return;
  int found = -1;
  for (int i = 0; i < n; i++)
    if (A[i][n-1]) found = i;
  if (found != -1) {
    for (int j = 0; j < n; j++)
      swap(A[n-1][j], A[found][j]);
    swap(b[n-1], b[found]);
  }
  if (A[n-1][n-1]) {
    ll Ai = inv(A[n-1][n-1]);
    for (int j = 0; j < n; j++)
      (A[n-1][j] *= Ai) %= mod;
    (b[n-1] *= Ai) %= mod;
    for (int i = 0; i < n-1; i++) {
      ll f = A[i][n-1];
      for (int j = 0; j < n; j++)
	(A[i][j] -= A[n-1][j]*f) %= mod;
      (b[i] -= b[n-1]*f) %= mod;
    }
  }
  solve(n-1);
  if (A[n-1][n-1]) {
    x[n-1] = b[n-1];
    for (int j = 0; j < n-1; j++)
      (x[n-1] -= A[n-1][j]*x[j]) %= mod;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 11;

  /*for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      A0[i][j] = A[i][j] = rand()%mod;
  for (int i = 0; i < n; i++)
  b0[i] = b[i] = rand()%mod;*/

  for (int i = 0; i < n; i++) {
    cout << "? " << i << endl;
    cin >> b[i];
    A[i][0] = 1;
    for (int j = 1; j < n; j++)
      A[i][j] = A[i][j-1]*i%mod;
  }
  solve(n);
  for (ll ans = 0; ans < mod; ans++) {
    ll p = 1, r = 0;
    for (int i = 0; i < n; i++) {
      (r += p*x[i]) %= mod;
      p = p*ans%mod;
    }
    if (!r) {
      cout << "! " << ans << endl;
      return 0;
    }
  }
  cout << "! -1" << endl;
  return 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << A[i][j] << ' ';
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      (b0[i] -= A0[i][j]*x[j]) %= mod;
    cout << b0[i] << ' ';
  }
}