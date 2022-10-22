#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k*2 > n-1) {
    cout << -1 << endl;
    return 0;
  }
  cout << n*k << '\n';
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= k; j++)
      cout << i+1 << ' ' << (i+j)%n+1 << '\n';
}