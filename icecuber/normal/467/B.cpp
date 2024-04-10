#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[1000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++)
    cin >> x[i];
  int y;
  cin >> y;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int d = x[i]^y;
    int a = k;
    while (d) d -= d&-d, a--;
    if (a >= 0) ans ++;
  }
  cout << ans << endl;
}