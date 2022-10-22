#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[500][500];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  int x = 0;
  int dx = -1, dy = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      if (dx == -1 && j && a[i][j] != a[i][0]) dx = j, dy = i;
    }
    x ^= a[i][0];
  }
  if (dx == -1 && !x) {
    cout << "NIE" << endl;
    return 0;
  }
  cout << "TAK" << endl;
  for (int i = 0; i < h; i++) {
    cout << (!x && i==dy)*dx+1 << ' ';
  }
  cout << endl;
}