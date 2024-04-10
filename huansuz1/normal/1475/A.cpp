#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    while (n % 2 == 0) {
      n /= 2;
    }
    cout << (n == 1 ? "NO" : "YES") << '\n';
  }
  return 0;
}