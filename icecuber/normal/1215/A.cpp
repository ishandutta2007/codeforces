#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  int mi = 1e9, ma = -1e9;
  for (int i = 0; i <= a1; i++)
    for (int j = 0; j <= a2; j++) {
      if (i*k1+j*k2 <= n) ma = max(ma, i+j);
      if (a1*(k1-1)+a2*(k2-1)+i+j >= n) mi = min(mi, i+j);
    }
  cout << mi << ' ' << ma << endl;
}