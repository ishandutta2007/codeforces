#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define data eglrjrelkgj
const int nax = 2510;
ull data[nax][nax];
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());

void add(int h, int w, ull v) {
  for (int r = h; r < nax; r += r&-r)
    for (int c = w; c < nax; c += c&-c)
      data[r][c] ^= v;
}
void add(int r1, int c1, int r2, int c2, ull v) {
  add(r2, c2, v);
  add(r1, c2, v);
  add(r2, c1, v);
  add(r1, c1, v);
}
ull get(int r1, int c1) {
  ull ret = 0;
  for (int r = r1; r; r -= r&-r)
    for (int c = c1; c; c -= c&-c)
      ret ^= data[r][c];
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, q;
  cin >> h >> w >> q;
  map<tuple<int,int,int,int>, ull> hash;
  while (q--) {
    int t, r1, c1, r2, c2;
    cin >> t >> r1 >> c1 >> r2 >> c2;
    if (t == 3) {
      cout << (get(r1, c1) == get(r2, c2) ? "Yes" : "No") << '\n';
    } else {
      r2++, c2++;
      if (t == 1) {
	hash[{r1,c1,r2,c2}] = mrand();
      }
      add(r1, c1, r2, c2, hash[{r1,c1,r2,c2}]);
    }
  }
}