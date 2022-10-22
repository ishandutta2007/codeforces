#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  int minx = w, maxx = 0, miny = h, maxy = 0;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      if (s[j] == 'B') {
	minx = min(minx, j);
	maxx = max(maxx, j);
	miny = min(miny, i);
	maxy = max(maxy, i);
      }
    }
  }

  cout << (maxy+miny)/2+1 << ' ' << (maxx+minx)/2+1 << endl;
}