#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int isprime[100001], a[100001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) isprime[i] = 1;
  int primes = 0;
  for (int i = 2; i <= n; i++) {
    if (!isprime[i]) continue;
    primes++;
    for (int j = i; j <= n; j += i)
      isprime[j] = 0, a[j] = primes;
  }
  for (int i = 2; i <= n; i++)
    cout << a[i] << ' ';
  cout << endl;
}