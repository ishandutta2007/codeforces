#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define forijk(a,b,c) for (int i = 0; i < a; i++) for (int j = 0; j < b; j++) for (int k = 0; k < c; k++)

ll mod = 1e9+7;
ll a[100][100];
ll r[100][100];
ll tmp[100][100];
ll n, m;
void mul(ll a[][100], ll b[][100], ll c[][100]) {
  fill_n((ll*)tmp, 100*100, 0);
  forijk(m,m,m) (tmp[i][j] += a[i][k]*b[k][j]) %= mod;
  copy_n((ll*)tmp, 100*100, (ll*)c);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  a[0][0] = a[0][m-1] = 1;
  for (int i = 1; i < m; i++)
    a[i][i-1] = 1;
  forijk(m,m,m)
    r[i][j] = i==j;
  while (n) {
    if (n&1) {
      mul(a,r,r);
    }
    mul(a,a,a);
    n >>= 1;
  }
  cout << r[0][0] << endl;
}