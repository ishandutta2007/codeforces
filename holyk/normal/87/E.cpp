// LUOGU_RID: 93219081
// Author:  HolyK
// Created: Tue Nov  8 01:22:19 2022
#include "bits/stdc++.h"

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

using namespace std;

using D = double;
using LD = long double;
using T = LD;

constexpr T EPS(1e-10);
const T PI = acosl(-1.L);
int sgn(T x) { return (x > EPS) - (x < -EPS); }
int cmp(T x, T y) { return sgn(x - y); }

struct Pt {
  T x, y;
  void read() {
    int a, b;
    cin >> a >> b, x = a, y = b;
  }
  void print() { cout << x << " " << y << "\n"; }

  explicit Pt(T x = 0, T y = 0) : x(x), y(y) {}
  Pt operator+(const Pt &r) const { return Pt(x + r.x, y + r.y); }
  Pt operator-(const Pt &r) const { return Pt(x - r.x, y - r.y); }
  Pt operator*(T r) const { return Pt(x * r, y * r); }
  Pt operator/(T r) const { return Pt(x / r, y / r); }
  bool operator<(const Pt &r) const { return x < r.x || x == r.x && y < r.y; }
  bool operator==(const Pt &r) const { return !cmp(x, r.x) && !cmp(y, r.y); }

  T operator^(const Pt &r) const { return x * r.x + y * r.y; }  // dot
  T operator*(const Pt &r) const { return x * r.y - y * r.x; }  // cross
  T cross(Pt a, Pt b) const { return (a - *this) * (b - *this); }

  T len2() const { return x * x + y * y; }
  T len() const { return sqrt(len2()); }

  Pt rotate(T r) const {
    return Pt(x * cos(r) - y * sin(r), x * sin(r) + y * cos(r));
  }

  Pt unit() const { return *this / len(); }
  Pt perp() const { return Pt(-y, x); }
  Pt norm() const { return perp().unit(); }

  Pt proj(Pt a, Pt b) const {
    Pt d = b - a;
    return a + d * ((d ^ (*this - a)) / d.len2());
  }
  Pt refl(Pt a, Pt b) const { return proj(a, b) * 2 - *this; }

  bool onSeg(Pt a, Pt b) const {
    return !sgn(cross(a, b)) && sgn((*this - a) ^ (*this - b)) <= 0;
  }
  int side(Pt a, Pt b) const { return sgn(a.cross(b, *this)); }
  int pos() const { return y > 0 || y == 0 && x > 0; }
};
bool argcmp(Pt a, Pt b) {
  return a.pos() != b.pos() ? a.pos() : a * b > EPS;
}

using Poly = vector<Pt>;
Poly mincowskySum(Poly a, Poly b) {
  int n = a.size(), m = b.size();
  Poly s(n + m);
  Pt a0 = a[0], b0 = b[0];
  for (int i = 0; i < n; i++)
    a[i] = i + 1 < n ? a[i + 1] - a[i] : a0 - a[i];
  for (int i = 0; i < m; i++)
    b[i] = i + 1 < m ? b[i + 1] - b[i] : b0 - b[i];
  s[0] = a0 + b0;
  for (int i = 0, j = 0, k = 1; k < n + m; k++) {
    if (j >= m || i < n && a[i] * b[j] > 0) {
      s[k] = a[i++];
    } else {
      s[k] = b[j++];
    }
    s[k] = s[k] + s[k - 1];
  }
  return s;
}

int inHull(Pt p, const Poly &h, int strict = 1) {
  if (h.empty()) return 0;
  int a = 1, b = h.size() - 1, c, r = !strict;
  if (b < 2) return r && p.onSeg(h[0], h[b]);
  if (h[b].side(h[0], h[a]) > 0) swap(a, b);
  if (p.side(h[0], h[a]) >= r || p.side(h[0], h[b]) <= -r) return 0;
  while (abs(a - b) > 1) c = (a + b) >> 1, (p.side(h[0], h[c]) > 0 ? b : a) = c;
  return p.side(h[a], h[b]) < r;
}

Poly convexHull(Poly p) {
  if (p.size() <= 1) return p;
  sort(p.begin(), p.end());
  Poly h(p.size() + 1);
  int s = 0, t = 0, i = 2;
  for (; i--; s = --t, reverse(p.begin(), p.end()))
    for (auto a : p) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], a) <= 0) t--;
      h[t++] = a;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

Poly readPoly() {
  int n;
  std::cin >> n;
  Poly a(n);
  for (auto &p : a) p.read();
  a = convexHull(a);
  return a;
}

void solve() {
  Poly a = readPoly(), b = readPoly(), c = readPoly();

  a = mincowskySum(a, b);
  a = mincowskySum(a, c);

  a = convexHull(a);

  int q;
  std::cin >> q;
  while (q--) {
    Pt p;
    p.read();
    std::cout << (inHull(p * 3, a, 0) ? "YES\n" : "NO\n");
  }
}


int main() {
  // freopen("t.in", "r", stdin);
  // freopen("t.out", "w", stdout);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}