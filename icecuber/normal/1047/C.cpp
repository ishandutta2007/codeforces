#include <iostream>
#include <map>

using namespace std;

const int m = 1e5;
int isprime[m];
int prime[m], primes = 0;

int a[500000];

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

int main() {
  for (int i = 2; i < m; i++) isprime[i] = 1;
  for (int i = 2; i < m; i++) {
    if (!isprime[i]) continue;
    prime[primes++] = i;
    for (int j = i*2; j < m; j += i)
      isprime[j] = 0;
  }
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int g = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    g = gcd(a[i], g);
  }

  int max_count = 0;
  map<int, int> count;
  for (int i = 0; i < n; i++) {
    a[i] /= g;
    for (int j = 0; prime[j]*prime[j] <= a[i]; j++) {
      int ok = 0;
      while (a[i]%prime[j] == 0) {
	a[i] /= prime[j];
	ok = 1;
      }
      if (ok) max_count = max(max_count, ++count[prime[j]]);
    }
    if (a[i] != 1) max_count = max(max_count, ++count[a[i]]);
  }
  if (max_count == 0) cout << -1 << endl;
  else cout << n-max_count << endl;
}