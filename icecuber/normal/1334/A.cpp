#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = 0, b = 0;
    int ok = 1;
    for (int i = 0; i < n; i++) {
      int na, nb;
      cin >> na >> nb;
      if (na < a || nb < b || nb-b > na-a) ok = 0;
      a = na, b = nb;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}