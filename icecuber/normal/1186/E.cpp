#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int acc[2001][2001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, q;
  cin >> h >> w >> q;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      int c = s[j]-'0';
      acc[i+1][j+1] = c;
      acc[i+h+1][j+1] = !c;
      acc[i+h+1][j+w+1] = c;
      acc[i+1][j+w+1] = !c;
    }
  }
  for (int i = 0; i < 2*h; i++)
    for (int j = 0; j < 2*w; j++)
      acc[i+1][j+1] += acc[i+1][j]+acc[i][j+1]-acc[i][j];
  auto f = [&](ll x, ll y) {
    ll rx = x%(w*2), ry = y%(h*2);
    ll ans = (x*y-rx*ry)/2;
    if (__builtin_popcount(x/(w*2))+__builtin_popcount(y/(h*2))&1)
      return ans+rx*ry-acc[ry][rx];
    else
      return ans+acc[ry][rx];
  };
  while (q--) {
    int y0,x0,y1,x1;
    cin >> y0 >> x0 >> y1 >> x1;
    x0--, y0--;
    cout << f(x1,y1)+f(x0,y0)-f(x1,y0)-f(x0,y1) << endl;
  }
}