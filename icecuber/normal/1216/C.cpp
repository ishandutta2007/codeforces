#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct rect {
  int x0, y0, x1, y1;
  int contains(int x, int y) {
    return x >= x0 && x <= x1 && y >= y0 && y <= y1;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  rect r[3];
  for (int i = 0; i < 3; i++) {
    cin >> r[i].x0 >> r[i].y0 >> r[i].x1 >> r[i].y1;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int x = j ? r[0].x0 : r[0].x1;
      int y = i ? r[0].y0 : r[0].y1;
      if (!r[1].contains(x,y) && !r[2].contains(x,y)) {
	cout << "YES" << endl;
	return 0;
      }
    }
  }

  if (r[1].x1 < r[2].x0 && r[1].x1 >= r[0].x0 && r[1].x1 < r[0].x1 ||
      r[2].x1 < r[1].x0 && r[2].x1 >= r[0].x0 && r[2].x1 < r[0].x1 ||
      r[1].y1 < r[2].y0 && r[1].y1 >= r[0].y0 && r[1].y1 < r[0].y1 ||
      r[2].y1 < r[1].y0 && r[2].y1 >= r[0].y0 && r[2].y1 < r[0].y1) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}