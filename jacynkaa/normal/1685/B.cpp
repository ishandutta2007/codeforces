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
template <class L, class R, class S> ostream &operator<<(ostream &out, tuple<L, R, S> p) {
   auto &[a, b, c] = p;
   return out << "(" << a << ", " << b << ", " << c << ")";
}
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

typedef vector<vector<int>> vii;
void add(string &S, vii &X) {
   debug(S);
   if (sz(S) < 2)
      return;
   int t = sz(S) / 2;

   if (sz(S) % 2 == 1)
      X[0].push_back(t);
   else {
      if (S[0] == 'A')
         X[1].push_back(t);
      else
         X[2].push_back(t);
   }
}

bool ok(int t, int i, vector<int> Y, vii X, int marg) {
   int j = i ^ 3;

   debug(i, j);
   sort(all(X[j]), greater<int>());
   debug(X[j]);

   rep(k, min(marg, sz(X[j]))) Y[i] += (X[j][k] - 1);
   return t <= Y[0] + Y[i];
}

bool solve() {
   int a, b, c, d;
   cin >> a >> b >> c >> d;
   string S;
   cin >> S;
   debug(S);
   if (count(all(S), 'A') != a + c + d) {
      debug("ZLE A");
      return false;
   }

   if (count(all(S), 'B') != b + c + d) {
      debug("ZLE B");
      return false;
   }

   vii X(3);

   string T;
   for (char c : S) {
      if (sz(T) && T.back() == c) {
         add(T, X);
         T = {c};
      } else
         T.push_back(c);
   }
   add(T, X);

   debug(X);

   vector<int> Y(3);
   rep(i, 3) { Y[i] = accumulate(all(X[i]), 0); }

   debug(Y);

   int marg = accumulate(all(Y), 0) - c - d;

   debug(marg);

   if (marg < 0)
      return false;
   if (!ok(c, 1, Y, X, marg)) {
      debug("WC", c);
      return false;
   }
   if (!ok(d, 2, Y, X, marg)) {
      debug("WD", c);

      return false;
   }

   return true;
}

void sol() {
   bool ok = solve();
   cout << (ok ? "YES" : "NO") << endl;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--)
      sol();
}