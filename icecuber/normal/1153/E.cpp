#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ax = -1, ay = -1, bx, by;
int query(int x1, int y1, int x2, int y2) {
  cout << "? " << x1+1 << ' ' << y1+1 << ' ' << x2 << ' ' << y2 << endl;
  int ans;
  cin >> ans;
  ans ^= ax >= x1 && ax < x2 && ay >= y1 && ay < y2;
  return ans%2;
}

void finish() {
  cout << "! " << ' ' << ax+1 << ' ' << ay+1 << ' ' << bx+1 << ' ' << by+1 << endl;
}

void pinpoint(int x1, int y1, int x2, int y2) {
  int xm = x1+x2>>1, ym = y1+y2>>1;
  if (x2-x1 == 1 && y2-y1 == 1) {
    if (ax == -1) {
      ax = x1;
      ay = y1;
    } else {
      bx = x1;
      by = y1;
    }
    return;
  }
  if (x2-x1 > 1) {
    if (query(x1,y1,xm,y2))
      pinpoint(x1,y1,xm,y2);
    else
      pinpoint(xm,y1,x2,y2);
  } else {
    if (query(x1,y1,x2,ym))
      pinpoint(x1,y1,x2,ym);
    else
      pinpoint(x1,ym,x2,y2);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i <= (n+1)/2; i++) {
    if (query(0,i,n,i+n/2)) {
      pinpoint(0,i,n,i+n/2);
      pinpoint(0,0,n,n);
      finish();
    }
  }
  for (int i = 0; i <= (n+1)/2; i++) {
    if (query(i,0,i+n/2,n)) {
      pinpoint(i,0,i+n/2,n);
      pinpoint(0,0,n,n);
      finish();
    }
  }
}