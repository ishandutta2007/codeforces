#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
typedef pair<ll,ll> point;
ll operator%(point a, point b) {
  return a.x*b.y-a.y*b.x;
}
bool angle_cmp(point a, point b) {
  return a%b > 0;
}

point p[300000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i].x >> p[i].y;
  sort(p, p+n);
  point base = p[0];
  for (int i = 0; i < n; i++) {
    p[i].x -= base.x;
    p[i].y -= base.y;
  }
  sort(p+1, p+n, angle_cmp);
  point mi(1e9,1e9), ma(-1e9,-1e9);
  for (int i = 0; i < n; i++) {
    mi.x = min(mi.x, p[i].x);
    mi.y = min(mi.y, p[i].y);
    ma.x = max(ma.x, p[i].x);
    ma.y = max(ma.y, p[i].y);
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, p[i].x+p[i].y-mi.x-mi.y);
    ans = max(ans, p[i].x-p[i].y-mi.x+ma.y);
    ans = max(ans,-p[i].x+p[i].y+ma.x-mi.y);
    ans = max(ans,-p[i].x-p[i].y+ma.x+ma.y);
  }
  cout << ans*2 << ' ';
  for (int i = 4; i <= n; i++)
    cout << (ma.x-mi.x+ma.y-mi.y)*2 << ' ';
  cout << endl;
}