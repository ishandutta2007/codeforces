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

#define int long long

const int MAXN = 1e6 + 99;
bool P[MAXN];
vector<int> T[MAXN];

int solve(vector<int> &A) {

   int res = 0;
   vector<int> X = {0};
   for (int a : A)
      if (a == 0)
         X.back()++;
      else
         X.push_back(0);

   rep(i, sz(X) - 1) { res += (X[i] + 1) * (X[i + 1] + 1) - 1; }

   debug(A, X, res);
   A.clear();
   return res;
}

void solve() {
   int e, n;
   cin >> n >> e;
   int res = 0;
   rep(i, n) {
      int a;
      cin >> a;
      if (a == 1)
         T[i % e].push_back(0);
      else {
         debug(a, P[a]);
         if (P[a])
            T[i % e].push_back(1);
         else
            res += solve(T[i % e]);
      }
   }
   rep(i, e) res += solve(T[i]);
   cout << res << endl;
}

void pre() {
   rep(i, MAXN) P[i] = true;

   for (int i = 2; i < MAXN; i++)
      if (P[i])
         for (int j = 2 * i; j < MAXN; j += i)
            P[j] = false;
}

int32_t main() {
   _upgrade;

   pre();
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}