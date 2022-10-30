// Hydro submission #62fb2df34b7288bafe6077dc@1660628467521
#include <bits/stdc++.h>
using namespace std;
bool mem1;
int n, m;
int a[105];
bool mem2;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[x]++;
    a[y + 1]--;
  }
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += a[i];
    if (cur == 0 || cur > 1) {
      cout << i << " " << cur << endl;
      return 0;
    }
  }
  cout << "OK\n";
  return 0;
}