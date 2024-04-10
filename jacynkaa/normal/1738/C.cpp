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

// even odd starting player status alicji
const int MAXN = 102;
bool tab[MAXN][MAXN][2][2];

#define BOB 1
#define ALICE 0

void pre() {
   tab[0][0][1][0] = tab[0][0][0][0] = 1;

   rep(i, MAXN) rep(j, MAXN) if (i + j > 0) rep(start, 2) rep(even, 2) {
      auto &cur = tab[i][j][start][even];
      if (start == BOB) {
         cur = 1;
         if (i)
            cur = min(tab[i - 1][j][ALICE][even], cur);
         if (j)
            cur = min(tab[i][j - 1][ALICE][even], cur);
      } else {
         if (i)
            cur = max(tab[i - 1][j][BOB][even], cur);
         if (j)
            cur = max(tab[i][j - 1][BOB][even ^ 1], cur);
      }
      debug(i, j, start, even, tab[i][j][start][even]);
   }
}

void solve() {
   int n;
   cin >> n;
   vector<int> X = {0, 0};
   const int C = 1e9 + 2;
   rep(i, n) {
      int a;
      cin >> a;
      a += C;
      X[a & 1]++;
   }
   debug(X);
   cout << (tab[X[0]][X[1]][ALICE][0] ? "Alice" : "Bob") << endl;
}

int32_t main() {
   _upgrade;
   pre();
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}