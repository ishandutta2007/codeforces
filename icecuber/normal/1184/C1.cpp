#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[50], y[50];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  n = n*4+1;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  for (int a = 0; a < n; a++) {
    int xmin = 1e9, xmax = -1e9, ymin = 1e9, ymax = -1e9;
    for (int i = 0; i < n; i++) {
      if (i == a) continue;
      xmin = min(xmin, x[i]);
      ymin = min(ymin, y[i]);
      xmax = max(xmax, x[i]);
      ymax = max(ymax, y[i]);
    }
    int xmas = 0, xmis = 0, ymas = 0, ymis = 0, ok = 1;
    for (int i = 0; i < n; i++) {
      if (i == a) continue;
      xmas += x[i]==xmax;
      xmis += x[i]==xmin;
      ymas += y[i]==ymax;
      ymis += y[i]==ymin;
      if (x[i] != xmin && x[i] != xmax && y[i] != ymin && y[i] != ymax)
	ok = 0;
    }
    if (ok && xmas > 1 && xmis > 1 && ymas > 1 && ymis > 1) {
      cout << x[a] << ' ' << y[a] << endl;
      return 0;
    }
  }
}