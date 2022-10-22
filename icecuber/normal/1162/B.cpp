#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[50][50], b[50][50];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];
  int ok = 1;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      cin >> b[i][j];
      if (b[i][j] < a[i][j]) swap(a[i][j], b[i][j]);
      if (j && (b[i][j] <= b[i][j-1] || a[i][j] <= a[i][j-1])) ok = 0;
      if (i && (b[i][j] <= b[i-1][j] || a[i][j] <= a[i-1][j])) ok = 0;
    }
  cout << (ok ? "Possible" : "Impossible") << endl;
}