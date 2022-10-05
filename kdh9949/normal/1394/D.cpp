#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

const int N = 200005;

int chk[N][3];
ll d[N][3];

const ll INF = ll(1e18);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vint> e(n + 1);
  vint h(n + 1);
  vll a(n + 1);  

  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> h[i];
  for(int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }

  function<ll(int, int, int)> f = [&](int x, int c, int y) {
    if(x > 1 && ((c > 0 && h[y] > h[x]) || (c < 0 && h[y] < h[x]))) return INF;
    if(chk[x][c + 1]) return d[x][c + 1];
    ll &r = d[x][c + 1];

    int bc = c;
    ll bs = 0;
    vll v;

    for(int i : e[x]) {
      if(i == y) continue;
      ll A = f(i, 1, x);
      ll B = f(i, -1, x);
      if(A == INF) {
        bs += B;
        bc++;
      }
      else if(B == INF) {
        bs += A;
        bc--;
      }
      else {
        bs += A;
        bc--;
        v.push_back(B - A);
      }
    }

    sort(all(v));
    ll mc = ll(e[x].size() + 1) / 2;
    r = (mc + abs(bc) / 2) * a[x] + bs;
    for(int i = 0; i < v.size(); i++) {
      bs += v[i];
      bc += 2;
      r = min(r, (mc + abs(bc) / 2) * a[x] + bs);
    }

    chk[x][c + 1] = 1;
    return r;
  };

  cout << f(1, 0, 0) << '\n';
  return 0;
}