#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef long double lf;
typedef long long ll;
typedef pair<ll, ll> point;
const int MAXN = 1e5 + 5;

ll dp[MAXN];
int j = 0;

#define x first
#define y second
lf ccw(point a, point b, point c) {
   return (lf) a.x * (b.y - c.y) + (lf) b.x * (c.y - a.y) + (lf) c.x * (a.y - b.y);
}

vector<point> h;

ll a[MAXN], b[MAXN];

int main() {
   int n; cin >> n;

   rep(i, n) cin >> a[i];
   rep(i, n) cin >> b[i];

   h.emplace_back(b[0], 0);

   for(int i = 1; i < n; ++i) {
      j = min(j, max(0, (int) h.size() - 2));
      for(; j + 1 < h.size() && h[j].x * a[i] + h[j].y >= h[j + 1].x * a[i] + h[j + 1].y; ++j);
      dp[i] = h[j].x * a[i] + h[j].y;
      point p = point(b[i], dp[i]);
      while(h.size() >= 2 && ccw(h[h.size() - 2], h.back(), p) >= 0) h.pop_back();
      h.push_back(p);
   }

   cout << dp[n - 1];
}