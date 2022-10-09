// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a=0, b=0;
    while (n--) {
      int x;
      cin >> x;
      (x == 1 ? a : b)++;
    }

    cout << ((a+2*b) % 2 == 0 && (a > 0 || b % 2 == 0) ? "YES\n" : "NO\n");
  }
}