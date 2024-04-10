#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> cnt(w+h, vector<int>(2));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	int a;
	cin >> a;
	cnt[i+j][a]++;
      }
    }
    int s = w+h-2;
    int ans = 0;
    for (int i = 0; i < s-i; i++) {
      ans += min(cnt[i][0]+cnt[s-i][0], cnt[i][1]+cnt[s-i][1]);
    }
    cout << ans << endl;
  }
}