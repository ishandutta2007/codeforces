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

const int MAXN = 3e5;

set<int> N[MAXN];

int get(int a) { return N[a].empty() || *(--N[a].end()) < a; }

int wynik = 0;

void add(int u, int v) {
   wynik -= get(u) + get(v);
   N[u].insert(v);
   N[v].insert(u);
   wynik += get(u) + get(v);
}

void remove(int u, int v) {
   wynik -= get(u) + get(v);
   N[u].erase(v);
   N[v].erase(u);
   wynik += get(u) + get(v);
}

int32_t main() {
   _upgrade;
   int n, m;
   cin >> n >> m;
   wynik = n;

   rep(i, m) {
      int a, b;
      cin >> a >> b;
      add(a, b);
   }

   int q;
   cin >> q;
   while (q--) {
      int x;
      cin >> x;
      if (x == 3) {
         cout << wynik << endl;
         continue;
      }
      int a, b;
      cin >> a >> b;
      if (x == 1)
         add(a, b);
      else
         remove(a, b);
      debug(wynik);
   }
}