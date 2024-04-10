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

const int A = 720;
const int MAXR = 23;

int add(int d) { return (d + 1) % A; }
int minu(int d) { return (d - 1 + A) % A; }

bool C[MAXR][A];
bool S[MAXR][A];

void clear() { rep(i, MAXR) rep(j, A) C[i][j] = S[i][j] = true; }

vector<pii> getN(pii p) {
   auto [a, r] = p;
   return {{add(a), r}, {minu(a), r}, {a, r + 1}, {a, r - 1}};
}

bool solve() {
   int n;
   cin >> n;
   rep(i, n) {
      char c;
      cin >> c;
      if (c == 'C') {
         int r, a1, a2;
         cin >> r >> a1 >> a2;
         a1 *= 2;
         a2 *= 2;
         for (int i = a1; i != a2; i = add(i))
            C[r][i] = false;
      } else {
         int r1, r2, a;
         cin >> r1 >> r2 >> a;

         a *= 2;
         for (int i = r1; i != r2; i++)
            S[i][a] = false;
      }
   }
   vector<pii> P = {{0, MAXR - 1}};
   set<pii> V;
   while (sz(P)) {
      auto p = P.back();
      auto [a, r] = p;
      P.pop_back();

      debug(a, r);

      if (r == 0)
         return true;

      if (!S[r][a] || V.count(p))
         continue;
      V.insert(p);

      P.push_back({add(a), r});
      P.push_back({minu(a), r});
      if (C[r][a])
         P.push_back({a, r - 1});
      if (r + 1 < MAXR && C[r + 1][a])
         P.push_back({a, r + 1});
   }
   return false;
}

void sol() {
   if (solve()) {
      cout << "YES\n";
   } else {
      cout << "NO\n";
   }
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      clear();
      sol();
   }
}