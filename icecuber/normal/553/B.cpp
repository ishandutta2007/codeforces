#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  fib[0] = fib[1] = 1;
  for (int i = 2; i < 100; i++)
    fib[i] = fib[i-1]+fib[i-2];

  ll n, k;
  cin >> n >> k;
  k--;
  int i = 0;
  while (i < n) {
    if (i+1 < n && k >= fib[n-i-1]) {
      k -= fib[n-i-1];
      cout << i+2 << ' ' << i+1 << ' ';
      i += 2;
    } else {
      cout << i+1 << ' ';
      i++;
    }
  }
  cout << endl;
}