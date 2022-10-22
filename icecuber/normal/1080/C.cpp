#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll h, w;
    cin >> h >> w;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    ll tot = w*h;
    ll blacks = tot/2;
    ll madewhite = ((x2-x1+1)*(y2-y1+1)+(x1+y1&1))/2;
    ll madeblack = ((x4-x3+1)*(y4-y3+1)+!(x3+y3&1))/2;
    ll x5 = max(x1,x3), y5 = max(y1,y3);
    ll x6 = min(x2,x4), y6 = min(y2,y4);
    ll madeblack_again = (x5<=x6&&y5<=y6)*((x6-x5+1)*(y6-y5+1)+(x5+y5&1))/2;
    blacks = blacks-madewhite+madeblack+madeblack_again;
    cout << tot-blacks << ' ' << blacks << endl;
  }
}