#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[667], y[667];
int hasrook[1000][1000];

int kx, ky;
void move(int nx, int ny) {
  if (hasrook[ny][nx]) nx = kx;
  cout << nx << ' ' << ny << endl;
  int k, rx, ry;
  cin >> k >> rx >> ry;
  if (k == -1)
    exit(0);
  hasrook[y[k]][x[k]] = 0;
  x[k] = rx;
  y[k] = ry;
  hasrook[y[k]][x[k]] = 1;
  kx = nx;
  ky = ny;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> kx >> ky;
  for (int i = 1; i <= 666; i++) {
    cin >> x[i] >> y[i];
    hasrook[y[i]][x[i]] = 1;
  }
  int gx = 500, gy = 500;
  for (int iter = 0; iter < 2; iter++) {
    while (kx != gx || ky != gy) {
      int dx = (kx<gx)-(kx>gx);
      int dy = (ky<gy)-(ky>gy);
      move(kx+dx,ky+dy);
    }
    int c[4] = {};
    for (int k = 1; k <= 666; k++)
      c[(x[k]>kx)+(y[k]>ky)*2]++;
    int mi = 1e9;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) {
	if (c[i*2+j] < mi) {
	  mi = c[i*2+j];
	  gx = j ? 1 : 999;
	  gy = i ? 1 : 999;
	}
      }
  }
}