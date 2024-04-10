#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
  ll x, y, z;
};
point o, base;

ll operator%(point a, point b) {
  return
    (a.y*b.z-a.z*b.y)*o.x+
    (a.z*b.x-a.x*b.z)*o.y+
    (a.x*b.y-a.y*b.x)*o.z;
}

point operator-(point a) {
  return point{-a.x,-a.y,-a.z};
}

bool operator<(point a, point b) {
  assert(a%base && b%base);
  ll sa = a%base > 0;
  ll sb = b%base > 0;
  if (sa != sb) return sa < sb;
  return a%b > 0;
}

point read() {
  point p;
  cin >> p.x >> p.y >> p.z;
  return p;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  o = read();
  mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
  base = point{ll(mrand()%ll(1e6)), ll(mrand()%ll(1e6)), ll(mrand()%ll(1e6))};

  int q;
  cin >> q;
  ll zeros = 0, pairs = 0, longs = 0;
  vector<point> added;
  map<point,int> cnt;

  map<point,int> ring;
  auto ring_add = [&](point p) {
    if (ring[p]++) return;
    auto it = ring.find(p);
    if (ring.size() >= 2) {
      auto a = (it == ring.begin() ? *ring.rbegin() : *prev(it)).first;
      auto b = (next(it) == ring.end() ? *ring.begin() : *next(it)).first;
      if (a%b < 0 && a%p >= 0 && p%b >= 0) longs = 0;
      if (a%p < 0 || p%b < 0) longs = 1;
    }
  };
  auto ring_rem = [&](point p) {
    if (--ring[p]) return;
    auto it = ring.find(p);
    if (ring.size() >= 2) {
      auto a = (it == ring.begin() ? *ring.rbegin() : *prev(it)).first;
      auto b = (next(it) == ring.end() ? *ring.begin() : *next(it)).first;
      if (a%p < 0 || p%b < 0) longs = 0;
      if (a%b < 0) longs = 1;
    }
    ring.erase(it);
  };

  while (q--) {
    char cmd;
    cin >> cmd;
    if (cmd == 'A') {
      point p = read();
      added.push_back(p);

      if (p%base == 0) zeros++;
      else {
	pairs += cnt[-p];
	cnt[p]++;

	ring_add(p);
      }
    } else if (cmd == 'R') {
      int id;
      cin >> id;
      point p = added[id-1];

      if (p%base == 0) zeros--;
      else {
	pairs -= cnt[-p];
	cnt[p]--;

	ring_rem(p);
      }
    } else assert(0);

    if (zeros) cout << 1 << endl;
    else if (pairs) cout << 2 << endl;
    else if (!longs && (int)ring.size() >= 3) cout << 3 << endl;
    else cout << 0 << endl;

    /*vector<point> v;
    for (auto [p,c] : ring) v.push_back(p);
    for (int i = 1; i < (int)v.size(); i++)
      assert(!(v[i] < v[i-1]));
    int true_longs = 0;
    for (int i = 0; i < (int)v.size(); i++) {
      point a = v[i], b = v[(i+1)%v.size()];
      if (a%b < 0) true_longs++;
    }
    if (true_longs != longs) cout << longs << ' ' << true_longs << ' ' << ring.size() << endl;*/
    //cout << true_long << endl;
    //assert(true_long == longs);
  }
}