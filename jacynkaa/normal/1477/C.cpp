#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
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
#define PII 3.14159265358979323846L
#ifdef LOCAL
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
#else
#define debug(...)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     \
   {}
#endif

typedef long double K;

const K EPS = 1e-10;
struct xy { // punkt w 2D
   K x, y;
   int id;
   xy(K xi, K yi) : x(xi), y(yi) {}
   xy(K xi, K yi, int id) : x(xi), y(yi), id(id) {}

   xy() {}
   K norm() const { return x * x + y * y; } // kwadrat(!) normy euklidesowej
};
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

typedef xy P;

K angle(P a, P b) { return atan2(det(a, b), a * b); }

bool valid(P a, P b, P c) {
   auto an = angle(a - b, c - b);

   debug(a.id, b.id, c.id);
   debug(an);
   return fabs(an) < PII * (0.5 - EPS);
}

int32_t main() {
   _upgrade;

   debug(angle({1, 1}, {2, 2}));
   debug(angle({1, 1}, {-1, -1}));

   debug(angle({0, 1}, {-1, -1}));
   debug(angle({0, 1}, {-1, 1}));

   int n;
   cin >> n;
   vector<P> R;
   rep(i, n) {
      int a, b;
      cin >> a >> b;
      R.emplace_back(a, b, i);
   }
   // debug(valid(R[0], R[4], R[1]));
   // debug(valid(R[4], R[0], R[1]));
   random_shuffle(all(R));

   vector<P> X;
   for (auto r : R) {
      X.push_back(r);
      int i = sz(X) - 3;
      while (i >= 0 && !valid(X[i], X[i + 1], X[i + 2])) {
         swap(X[i + 1], X[i + 2]);
         --i;
      }
   }
   for (auto p : X) {
      cout << p.id + 1 << " ";
   }
   cout << endl;
}