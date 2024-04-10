#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fori(a) for (int i = 0; i < a; i++)
#define forij(a,b) fori(a) for (int j = 0; j < b; j++)
#define forijk(a,b,c) forij(a,b) for (int k = 0; k < c; k++)

ll mod = 1e9+7;
ll inv(ll a) {
  a %= mod;
  ll p = mod-2;
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

ll a[51][51], r[51][51], tmp[51][51];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  int c[2] = {};
  for (int&v : A) {
    cin >> v;
    c[v]++;
  }
  int unorder = 0;
  for (int i = 0; i < c[0]; i++)
    unorder += A[i];

  ll n2 = n*(n-1)/2;
  ll in2 = inv(n2);
  n = n/2+1;
  forij(n,n) r[i][j] = i==j;
  fori(n) {
    if (i)
      a[i][i-1] = (i*i)*in2%mod;
    a[i][i] = (n2-i*i-(c[0]-i)*(c[1]-i))*in2%mod;
    if (i < n-1)
      a[i][i+1] = (c[0]-i)*(c[1]-i)*in2%mod;
  }
  while (k) {
    if (k&1) {
      forij(n,n) tmp[i][j] = 0;
      forijk(n,n,n)
	(tmp[i][j] += r[i][k]*a[k][j]) %= mod;
      forij(n,n) r[i][j] = tmp[i][j];
    }
    forij(n,n) tmp[i][j] = 0;
    forijk(n,n,n)
      (tmp[i][j] += a[i][k]*a[k][j]) %= mod;
    forij(n,n) a[i][j] = tmp[i][j];

    k >>= 1;
  }
  cout << r[unorder][0] << endl;
}