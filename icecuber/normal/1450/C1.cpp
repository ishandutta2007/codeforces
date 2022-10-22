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
    vector<string> a(n);
    vector<array<int,2>> c[2][3];

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 'X') c[0][(i+j)%3].push_back({i,j});
        if (a[i][j] == 'O') c[1][(i+j)%3].push_back({i,j});
      }
    }

    int tot = 0;
    for (int i : {0,1})
      for (int j : {0,1,2})
        tot += c[i][j].size();

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j || (int)(c[0][i].size()+c[1][j].size()) > tot/3) continue;
        for (auto [y,x] : c[0][i]) a[y][x] ^= 'X'^'O';
        for (auto [y,x] : c[1][j]) a[y][x] ^= 'X'^'O';
        for (int r = 0; r < n; r++)
          cout << a[r] << endl;
        goto finish;
      }
    }
  finish:;
  }
}