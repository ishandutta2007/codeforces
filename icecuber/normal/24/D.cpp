#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double x[1000], y[1000], z[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  int r, c;
  cin >> r >> c;
  c--, r = h-r;
  if (w == 1) {
    cout << r*2 << endl;
    return 0;
  }
  for (int j = 0; j < w; j++)
    x[j] = c==j;
  double ans = 0;
  for (int i = 0; i < r; i++) {
    fill_n(z, w, 0);
    for (int k = 0; k < 100; k++) {
      fill_n(y, w, 0);
      for (int j = 1; j < w-1; j++) {
	y[j] += x[j]*0.25;
	y[j-1] += x[j]*0.25;
	y[j+1] += x[j]*0.25;
	z[j] += x[j]*0.25;
	ans += (k+1)*x[j]*0.25;
      }
      y[0] += x[0]/3;
      y[1] += x[0]/3;
      z[0] += x[0]/3;
      ans += (k+1)*x[0]/3;
      y[w-1] += x[w-1]/3;
      y[w-2] += x[w-1]/3;
      z[w-1] += x[w-1]/3;
      ans += (k+1)*x[w-1]/3;
      swap(x,y);
    }
    swap(x,z);
  }
  cout << setprecision(20) << ans << endl;
}