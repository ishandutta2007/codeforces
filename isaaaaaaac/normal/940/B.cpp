#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <LL, LL> pi;

map <LL, LL> dis, vis;
priority_queue <pi, vector <pi>, greater <pi> > Q;

inline void Ins(LL d, LL x) {
  if (!dis.count(x) || dis[x] > d) {
    Q.push(make_pair(d, x));
    dis[x] = d;
  }
}

int main() {
  LL n, k, a, b;
  cin >> n >> k >> a >> b;
  Q.push(make_pair(0, n));
  while (!Q.empty()) {
    LL x = Q.top().second, d = Q.top().first;
    Q.pop();
    if (x == 1) { cout << d << endl; return 0; }
    if (vis.count(x)) continue;
    vis[x] = d;
    if (x % k == 0) {
      Ins(d + b, x / k);
      Ins(d + a * (x - 1), 1);
    }
    else {
      LL nxt = x / k * k;
      Ins((x - nxt) * a + d, nxt);
    }
  }
  return 0;
}