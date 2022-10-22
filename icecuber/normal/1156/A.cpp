#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i-1] || a[i] == 3 && a[i-1] == 2 || a[i] == 2 && a[i-1] == 3) {
      cout << "Infinite" << endl;
      return 0;
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i-1] == 1 && a[i] == 2 || a[i-1] == 2 && a[i] == 1)
      ans += 3;
    if (a[i-1] == 1 && a[i] == 3 || a[i-1] == 3 && a[i] == 1)
      ans += 4;
  }
  for (int i = 2; i < n; i++)
    if (a[i-2] == 3 && a[i-1] == 1 && a[i] == 2) ans--;
  cout << "Finite" << endl;
  cout << ans << endl;
}