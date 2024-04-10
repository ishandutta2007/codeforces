#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 100000, P = 1000000007;
bool IsPrime[MAXN + 1];
int Phi[MAXN + 1], SumCoprime[MAXN + 1];
vector<int> Primes;

void sieve(int n) {
  IsPrime[1] = false;
  for (int i = 2; i <= n; i++)
    IsPrime[i] = true;
  Phi[1] = 1;

  for (int i = 2; i <= n; i++) {
    if (IsPrime[i]) {
      Primes.push_back(i);
      Phi[i] = i - 1;
    }
    for (int p : Primes) {
      int t = i * p;
      if (t > n)
        break;
      IsPrime[t] = false;
      if (i % p == 0) {
        Phi[t] = Phi[i] * p;
        break;
      } else {
        Phi[t] = Phi[i] * (p - 1);
      }
    }
  }
}

int sum(int m) {
  return int((big)m * (m - 1) / 2 % P);
}

int gcd(int a, int b) {
  while (a) {
    int t = b % a;
    b = a;
    a = t;
  }
  return b;
}

inline big lcm(int a, int b) {
  return (big)a / gcd(a, b) * b;
}

int main() {
  int n;
  scanf("%d", &n);

  sieve(n);
  
  int ans = 0;
  for (int d = 1; d < n; d++)
    for (int m = 2 * d; m < n; m += d) {
      int c = n - m;
      ans = int((ans + (big)Phi[m / d] * (lcm(c, d) % P)) % P);
    }
  printf("%d\n", ans);

  return 0;
}