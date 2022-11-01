#include <bits/stdc++.h>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
#define MOD 1000000007

int n;
ll x[300005];
ll p2[300005];

int main() {
  p2[0] = 1;
  FO(i,1,300005) p2[i] = p2[i-1]*2 % MOD;

  scanf("%d", &n);
  FO(i,0,n) {
    scanf("%lld", &x[i]);
  }
  sort(x,x+n);
  ll sm = 0, res = 0;
  for (int i = n-2; i >= 0; i--) {
    sm = (sm + p2[n-1-i-1]) % MOD;
    res = (res + sm * (MOD-x[i])) % MOD;
  }
  sm = 0;
  FO(i,1,n) {
    sm = (sm + p2[i-1]) % MOD;
    res = (res + sm * x[i]) % MOD;
  }
  printf("%lld\n", res);
}