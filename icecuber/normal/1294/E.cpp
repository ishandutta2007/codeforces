#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }

  int ans = 0;
  for (int j = 0; j < w; j++) {
    vector<int> cnt(h);
    for (int i = 0; i < h; i++) {
      if (a[i][j]%w == j && a[i][j] < w*h) {
	cnt[(i-a[i][j]/w+h)%h]++;
      }
    }
    int best = h;
    for (int i = 0; i < h; i++) {
      best = min(best, h-cnt[i]+i);
    }
    ans += best;
  }
  cout << ans << endl;
}