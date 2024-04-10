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

set<pii> S;
int n;

vector<int> ask(int x) {
   ++x;
   cout << "? " << x << endl;
   vector<int> X(n);
   rep(i, n) cin >> X[i];
   return X;
}

void add(vector<int> X, int a) { rep(i, n) if (X[i] == 1) S.insert(minmax(i, a)); }

int32_t main() {
   cin >> n;

   auto T = ask(0);
   add(T, 0);

   set<int> P, NP;

   rep(i, n) if (i > 0) {
      if (T[i] % 2 == 0)
         P.insert(i);
      else
         NP.insert(i);
   }
   debug(P, NP);

   if (sz(P) < sz(NP))
      swap(NP, P);

   debug(NP);
   for (int a : NP) {
      auto T = ask(a);
      add(T, a);
   }

   cout << "!" << endl;
   for (auto p : S) {
      cout << p.st + 1 << " " << p.nd + 1 << endl;
   }
}