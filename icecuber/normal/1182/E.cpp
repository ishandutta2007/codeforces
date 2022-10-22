#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+6, mod2 = 1e9+7;
const ll N = 5;

ll tmp[N][N];
void matmul(ll a[N][N], ll b[N][N], ll c[N][N]) {
  fill_n((ll*)tmp, N*N, 0);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
	(tmp[i][j] += a[i][k]*b[k][j]) %= mod;
  copy_n((ll*)tmp, N*N, (ll*)c);
}

ll mypow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p%2) r = a*r%mod2;
    a = a*a%mod2;
    p >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, f1, f2, f3, c;
  cin >> n >> f1 >> f2 >> f3 >> c;
  n -= 3;
  c = c*c%mod2;
  ll a[N][N] = {{1,1,1,1,0},
		{1,0,0,0,0},
		{0,1,0,0,0},
		{0,0,0,1,1},
		{0,0,0,0,1}};
  ll r[N][N] = {};
  for (int i = 0; i < N; i++) r[i][i] = 1;
  while (n) {
    if (n%2) matmul(a, r, r);
    matmul(a,a,a);
    n >>= 1;
  }
  /*for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << r[i][j] << ' ';
    }
    cout << endl;
    }*/
  ll ans = 1;
  ll x0[N] = {f3,f2,f1,c,c};
  for (int i = 0; i < N; i++) {
    (ans *= mypow(x0[i], r[0][i])) %= mod2;
  }
  cout << ans << endl;
}