#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, c;
const int MAXF = 700010;
const ll MOD = 1000003;

ll brzoPot(int x, int n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  ll tmp = brzoPot(x, n / 2);
  tmp *= tmp;
  tmp %= MOD;
  if (n & 1) {
    tmp *= x;
    tmp %= MOD;
  }
  return tmp;
}

ll fact[MAXF];
ll factinv[MAXF];

int main() {
  fact[0] = 1;
  factinv[0] = 1;
  for (int i = 1; i < MAXF; i++) {
    fact[i] = fact[i-1] * i;
    fact[i] %= MOD;
    factinv[i] = brzoPot(fact[i], MOD - 2);
  }

  ll sol = 0;
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; i++) {
//    cout << fact[i+c-1] << " " << factinv[c-1] << " " << factinv[i] << endl;
    ll tmp = fact[i+c-1]*factinv[c-1];
    tmp %= MOD;
    tmp *= factinv[i];
    tmp %= MOD;
//    cout << tmp << endl;
    sol += tmp;
    if (sol >= MOD) sol -= MOD;
  }
  printf("%I64d", sol);

  return 0;
}