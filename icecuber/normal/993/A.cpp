#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
typedef pair<int,int> point;

int in(point a, point l, point r) {
  return a.x >= l.x && a.y >= l.y && a.x <= r.x && a.y <= r.y;
}
point operator-(point a, point b) {
  return {a.x-b.x,a.y-b.y};
}
ll operator%(point a, point b) {
  return a.x*b.y-a.y*b.x;
}
int cross(point a, point b, point c, point d) {
  return
    ((b-a)%(c-a) > 0) != ((b-a)%(d-a) > 0) &&
    ((d-c)%(a-c) > 0) != ((d-c)%(b-c) > 0);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  point a[4], b[4];
  point a0(1e9,1e9), a1(-1e9,-1e9);
  for (int i = 0; i < 4; i++) {
    cin >> a[i].x >> a[i].y;
    a0.x = min(a0.x, a[i].x);
    a0.y = min(a0.y, a[i].y);
    a1.x = max(a1.x, a[i].x);
    a1.y = max(a1.y, a[i].y);
  }
  point b0(1e9,1e9), b1(-1e9,-1e9);
  for (int i = 0; i < 4; i++) {
    cin >> b[i].x >> b[i].y;
    if (in(b[i], a0, a1)) goto yes;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (cross(a[i],a[i+1&3],b[j],b[j+1&3])) goto yes;
    }
  }
  for (int i = 0; i < 4; i++) {
    b[i] = {b[i].x-b[i].y,b[i].x+b[i].y};
    b0.x = min(b0.x, b[i].x);
    b0.y = min(b0.y, b[i].y);
    b1.x = max(b1.x, b[i].x);
    b1.y = max(b1.y, b[i].y);
    a[i] = {a[i].x-a[i].y,a[i].x+a[i].y};
  }
  for (int i = 0; i < 4; i++) {
    if (in(a[i], b0, b1)) goto yes;
  }
  cout << "NO" << endl;
  return 0;
 yes:
  cout << "YES" << endl;
}