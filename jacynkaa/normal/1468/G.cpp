#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
ostream &operator<<(ostream &out, string str) {
   for (char c : str)
      out << c;
   return out;
}
template <class L, class R> ostream &operator<<(ostream &out, pair<L, R> p) { return out << "(" << p.st << ", " << p.nd << ")"; }
template <class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
   out << '{';
   for (auto it = a.begin(); it != a.end(); it = next(it))
      out << (it != a.begin() ? ", " : "") << *it;
   return out << '}';
}
void dump() { cerr << "\n"; }
template <class T, class... Ts> void dump(T a, Ts... x) {
   cerr << a << ", ";
   dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
typedef long double K;

const K EPS = 1e-9;
struct xy { // punkt w 2D
   K x, y;
   xy(K xi, K yi) : x(xi), y(yi) {}
   xy() {}
   K norm() const { return x * x + y * y; } // kwadrat(!) normy euklidesowej
};
typedef xy P;
xy operator+(xy a, xy b) { return xy(a.x + b.x, a.y + b.y); }
xy operator-(xy a, xy b) { return xy(a.x - b.x, a.y - b.y); }
xy operator*(xy a, K f) { return xy(a.x * f, a.y * f); }
xy operator/(xy a, K f) { return xy(a.x / f, a.y / f); }
xy cross(xy a) { return xy(-a.y, a.x); } // obrot o 90 stopni
K operator*(xy a, xy b) { return a.x * b.x + a.y * b.y; }
K det(xy a, xy b) { return a.x * b.y - b.x * a.y; }
// mowi czy jak bylismy w X, jestesmy w Y i bedziemy w Z to skrecamy w lewo(right-prawo)
bool left(xy X, xy Y, xy Z) { return det(Y - X, Z - Y) > EPS; }
bool right(xy X, xy Y, xy Z) { return det(Y - X, Z - Y) < -EPS; }

struct line { // prosta {v: n*v=c} (n - wektor normalny)
   P n;
   K c;
   line(P ni, K ci) : n(ni), c(ci) {}
   line() {}
};
// Czy punkt lezy na prostej?
bool on_line(P a, line p) { return fabs(p.n * a - p.c) < EPS; }
// Prosta przechodzaca przez 2 punkty ccw. Zalozenie: a!=b
line span(P a, P b) { return line(cross(b - a), det(b, a)); }
// Symetralna odcinka. Zalozenie: a!=b
line median(P a, P b) { return line(b - a, (b - a) * (b + a) * 0.5); }
// Przeciecie 2 prostych
P intersection(line p, line q) {
   K d = det(p.n, q.n);
   if (fabs(d) < EPS)
      throw "rownolegle";
   return cross(p.n * q.c - q.n * p.c) / d;
}
// Prosta rownolegla przechodzaca przez punkt
line parallel(P a, line p) { return line(p.n, p.n * a); }
// Prosta prostopadla przechodzaca przez punkt
line perp(P a, line p) { return line(cross(p.n), det(p.n, a)); }
// Odleglosc punktu od prostej
K dist(P a, line p) { return fabs(p.n * a - p.c) / sqrt(p.n.norm()); }
K dist(P a, P b) {
   P tmp = a - b;
   return sqrt(tmp.x * tmp.x + tmp.y * tmp.y);
}
// Rzut prostokatny punktu na prosta
P proj(P a, line p) { return a + p.n * ((p.c - p.n * a) / p.n.norm()); }

int32_t main() {
   _upgrade;

   int n, H;
   cin >> n >> H;

   vector<pii> X(n);
   rep(i, n) cin >> X[i].st >> X[i].nd;
   for (auto &x : X) {
      x.st -= X.back().st;
      x.nd -= X.back().nd + H;
   }
   reverse(all(X));
   // debug(X);

   P wieza(0, 0);
   P best(X[0].st, X[0].nd);
   long double res = 0;
   for (int i = 1; i < n; i++) {
      P cur(X[i].st, X[i].nd);
      // debug(det(best, cur));
      if (det(best, cur) < 0) {
         // debug(i);
         auto line1 = span(cur, P(X[i - 1].st, X[i - 1].nd));
         auto line2 = span(wieza, best);
         auto przeciecie = intersection(line1, line2);
         res += dist(cur, przeciecie);
         // debug(res);
         best = cur;
      } else if (det(best, cur) < EPS) {
         if (best.x == X[i - 1].st && best.y == X[i - 1].nd) {
            res += dist(cur, P(X[i - 1].st, X[i - 1].nd));
         }
         best = cur;
      }
   }
   cout << res << endl;
}