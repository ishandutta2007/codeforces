#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> f(int w, int h, int x, int y) {
  vector<int> ans(1e6);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      ans[abs(i-y)+abs(j-x)]++;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(1e6);
  int ma = 0, mi = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
    ma = max(ma, a);
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] != i*4) {
      mi = i-1;
      break;
    }
  }
  //cout << mi << ' ' << ma << endl;
  for (int w = 1; w <= 1e6; w++) {
    int h = n/w;
    if (n%w) continue;
    int x = mi, y = w+h-2-ma-x;
    for (int k : {0,1}) {
      if (x < 0 || y < 0 || x >= w || y >= h) continue;
      //cout << w << ' ' << h << ' '<< x << ' ' << y << endl;
      auto target = f(w,h,x,y);
      if (target == cnt) {
	cout << h << ' ' << w << endl;
	cout << y+1 << ' ' << x+1 << endl;
	return 0;
      }
    }
  }
  cout << -1 << endl;
}