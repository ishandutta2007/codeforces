#include <bits/stdc++.h>
using namespace std;

int a[15];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ok = 0;
  for (int i = 0; i < 1<<n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++)
      sum += (i>>j&1?1:-1)*a[j];
    if (sum%360 == 0) ok = 1;
  }
  cout << (ok ? "YES" : "NO") << endl;
}