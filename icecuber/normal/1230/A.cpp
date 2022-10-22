#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a[4];
  for (int&v : a) cin >> v;
  for (int i = 0; i < 1<<4; i++) {
    int x = 0, y = 0;
    for (int j = 0; j < 4; j++)
      (i>>j&1 ? x : y) += a[j];
    if (x == y) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}