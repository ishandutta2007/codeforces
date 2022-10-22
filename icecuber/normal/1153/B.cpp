#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[100], y[100];
int ans[100][100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, tmp;
  cin >> h >> w >> tmp;
  for (int i = 0; i < w; i++)
    cin >> x[i];
  for (int i = 0; i < h; i++)
    cin >> y[i];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> ans[i][j];
      if (ans[i][j])
	ans[i][j] = min(x[j], y[i]);
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
}