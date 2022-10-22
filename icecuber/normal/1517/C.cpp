#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int&v : p) cin >> v;
  vector<vector<int>> ans(n,vector<int>(n));
  for (int i = 0; i < n; i++) {
    int x = i, y = i;
    for (int j = 0; j < p[i]; j++) {
      while (ans[y][x]) {
        if (x && !ans[y][x-1]) x--;
        else if (y+1 < n && !ans[y+1][x]) y++;
        else assert(0);
      }
      ans[y][x] = p[i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++)
      cout << ans[i][j] << ' ';
    cout << endl;
  }
}