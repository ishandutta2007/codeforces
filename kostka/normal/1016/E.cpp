//Bartek Kostka
//  You are not prepared!

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  double sy, a, b;
  scanf("%lf%lf%lf", &sy, &a, &b);
  int n;
  scanf("%d", &n);
  vector <pair <double, double> > X(n+1);
  X[0] = {-1e30L, -1e30L};
  vector <double> pref(n+2);
  for(int i=1; i<=n; i++) scanf("%lf%lf", &X[i].x, &X[i].y);
  X.emplace_back(1e30, 1e30);
  for(int i=1; i<=n; i++) pref[i] = X[i].y - X[i].x;
  for(int i=1; i<=n+1; i++) pref[i] += pref[i-1];
  int q;
  scanf("%d", &q);
  for(int i=0; i<q; i++) {
    double px, py;
    scanf("%lf%lf", &px, &py);
    double lx = px + 1.0L * (double)(a - px) * (double)(py) / (double)(py - sy);
    double rx = px + 1.0L * (double)(b - px) * (double)(py) / (double)(py - sy);
    // cerr << "H" << lx << " " << rx << "\n";
    int it = max(1, int(distance(X.begin(), prev(upper_bound(ALL(X), make_pair(ceil(lx), 1e30))))));
    int jt = distance(X.begin(), prev(lower_bound(ALL(X), make_pair(ceil(rx), -1e30))));
    // cerr << it << " " << jt << "\n";
    double ret = 0.0;
    // cerr << "R" << ret << "\n";
    if(it == jt) ret += max(0.0, min(X[it].y, rx)-max(lx, X[it].x));
    else {
      ret += pref[jt] - pref[it-1];
      if(X[it].x <= lx) ret -= min(X[it].y, lx) - X[it].x;
      if(rx <= X[jt].y) ret -= X[jt].y - max(X[jt].x, rx);
    }
    // cerr << "RW" << ret << "\n";
    ret *= 1.0L * (double)(py - sy) / py;
    printf("%.20lf\n", ret);
  }
  return 0;
}