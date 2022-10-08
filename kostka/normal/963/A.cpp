//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int MOD = 1e9+9;

int pot(int a, int b, int m = MOD) {
  if(b == 0) return 1;
  int q = pot(a, b/2, m);
  int q2 = (1LL*q*q)%m;
  if(b % 2) return (1LL*q2*a)%m;
  else return q2;
}

int inv(int x) {
  return pot(x, MOD-2);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  vector <int> A(k), B(k);
  A[0] = pot(a, n);
  B[0] = 1;
  for(int i=1; i<k; i++) {
    A[i] = (1LL*A[i-1]*inv(a))%MOD;
    B[i] = (1LL*B[i-1]*b)%MOD;
  }
  int tmp = 0;
  for(int i=0; i<k; i++) {
    tmp += ((s[i] == '+' ? 1LL : -1LL) * A[i] * B[i])%MOD;
    tmp %= MOD;
  }
  int q = (1LL * pot(inv(a), k) * pot(b, k)) % MOD;
  int gr = (n+1) / k;
  // cerr << q << "\n";
  if(q == 1) {
    int ret = 1LL * tmp * gr % MOD;
    ret += MOD;
    ret %= MOD;
    cout << ret << "\n";
  } else {
    int ret = ((1LL * tmp * (1 - pot(q, gr))) % MOD * inv(1-q)) % MOD;
    ret += MOD;
    ret %= MOD;
    cout << ret << "\n";
  }
  return 0;
}