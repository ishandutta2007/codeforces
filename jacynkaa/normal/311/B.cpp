#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
// mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
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
#define debug(...) 42
#endif

#define int long long

int n, m, p;

const int MAXP = 101;
const int MAXN = 1e5 + 9;
const int inf = 1e18;

typedef pair<ll, ll> P;

inline bool left(P &a, P &b, P &c) { return (b.st - a.st) * (c.nd - a.nd) - (c.st - a.st) * (b.nd - a.nd) < 0; }

inline void add_point(deque<P> &hull, P pt) {
   while (sz(hull) > 1 && left(hull[sz(hull) - 2], hull[sz(hull) - 1], pt))
      hull.pop_back();
   hull.pb(pt);
}

int get_val(P pt, int t) { return t * pt.st + pt.nd; }

int get_val(deque<P> &hull, int t) {
   if (sz(hull)) {
      while (sz(hull) > 1 && get_val(hull[0], t) >= get_val(hull[1], t))
         hull.pop_front();
      return get_val(hull[0], t);
   }
   return inf;
}

deque<P> H[MAXP];

int32_t main() {
   _upgrade;
   cin >> n >> m >> p;
   p = min(m, p);

   vector<int> D(n);

   for (int i = 1; i < n; i++) {
      int d;
      cin >> d;
      D[i] = d + D[i - 1];
   }

   debug(D);
   vector<int> X;
   rep(i, m) {
      int h, t;
      cin >> h >> t;
      X.push_back(t - D[--h]);
   }

   sort(all(X), greater<int>());

   debug("przed", X);

   int M = X[0];

   for (auto &x : X)
      x = M - x;

   debug(X);

   add_point(H[1], {X[0], accumulate(all(X), 0LL)});

   int maks = inf;
   rep(i, m) for (int k = 2; k <= p; k++) {
      int t = m - i;
      int dp = get_val(H[k - 1], t);
      int val = dp - t * X[i];
      maks = min(maks, val);
      add_point(H[k], {X[i], val});
   }
   cout << maks << endl;
}