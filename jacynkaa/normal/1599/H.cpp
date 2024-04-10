#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
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

#define int long long

pii X;
pii Y;

int get(int x, pii X) { return max({min(x - X.st, x - X.nd), min(X.st - x, X.nd - x), 0ll}); }

int getDC(int x, int y) { return get(x, X) + get(y, Y); }

int getD(int x, int y) {
   cout << "? " << x << " " << y << endl;
   //   return getDC(x, y);
   int a;
   cin >> a;
   return a;
}

const int M = 1e9;

int getX(int y) {
   int e = getD(1, y);
   int f = getD(M, y);
   int c = (1 + M + e - f) / 2;
   return getD(c, y);
}

int getY(int x) {
   int e = getD(x, 1);
   int f = getD(x, M);
   int c = (1 + M + e - f) / 2;
   return getD(x, c);
}

void ans(int a, int b, int c, int d) {
   cout << "! " << a << " " << b << " " << c << " " << d << endl;
   // assert(a == X.st && b == Y.st && c == X.nd && d == Y.nd);
}

int32_t main() {
   // cin >> X.st >> Y.st >> X.nd >> Y.nd;
   int B = 1 + getX(1);
   int A = 1 + getY(1);
   int D = M - getX(M);
   int C = M - getY(M);
   ans(A, B, C, D);
}