#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x[100000], y[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int d1, d2;
  cin >> d1 >> d2;
  d1 *= d1;
  d2 *= d2;
  for (int i = 0; i < n; i++) {
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    x[i] = ax-bx;
    y[i] = ay-by;
  }
  int alreadysaid = 0;
  int hellos = 0;
  for (int i = 0; i < n; i++) {
    ll aa = x[i]*x[i]+y[i]*y[i];
    //cout << aa << ' ' << d1 << ' ' << d2 << ' ' << alreadysaid << endl;
    if (aa <= d1 && !alreadysaid) {
      hellos++;
      alreadysaid = 1;
    } else if (aa > d2 && alreadysaid) alreadysaid = 0;
    else if (!alreadysaid && i) {
      ll dx = x[i-1]-x[i], dy = y[i-1]-y[i];
      ll da = dx*x[i]+dy*y[i];
      ll dd = dx*dx+dy*dy;
      if (da < 0 && -da < dd && dd*d1 >= aa*dd-da*da) {
	hellos++;
	alreadysaid = aa < d2;
      }
    }
  }
  cout << hellos << endl;
}