#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 70;
ll dp[1000][M];
int isprime[1000];
ll prime[1000], primes = 0;

int main() {
  for (int i = 2; i < 1000; i++) isprime[i] = 1;
  for (int i = 2; i < 1000; i++) {
    if (!isprime[i]) continue;
    prime[primes++] = i;
    for (int j = i*2; j < 1000; j += i)
      isprime[j] = 0;
  }
  assert(primes > M);
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  //dp[i][j] = minimum integer consisting of j first primes with i divisors
  for (int i = 1; i <= n; i++) {
    dp[i][0] = i == 1 ? 1 : 1e18;
    for (int j = 1; j < M; j++) {
      dp[i][j] = dp[i][j-1];
      ll p = prime[j-1];
      for (int k = 1;; k++) {
	if (i%(k+1) == 0 && (double)dp[i/(k+1)][j-1]*p < 2e18) {
	  dp[i][j] = min(dp[i][j], dp[i/(k+1)][j-1]*p);
	}
	if ((double)p*prime[j-1] > 2e18) break;
	p *= prime[j-1];
      }
    }
  }
  cout << dp[n][59] << endl;
}