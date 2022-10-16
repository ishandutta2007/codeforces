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
int S[MAXN];
vector<int> C;
vector<int> G[MAXN];
int n;

int dfs(int x, bool add = false, int p = -1) {
   vector<int> T;
   for (int y : G[x])
      if (y != p) {
         int t = dfs(y, add, x);
         T.push_back(t);
      }

   int m = sz(T) ? *max_element(all(T)) : 0;
   int sum = accumulate(all(T), 0);
   debug(x, sum);
   int poz = n - 1 - sum;

   debug(poz);

   if (add && max(m, poz) <= n / 2)
      C.push_back(x);

   return S[x] = sum + 1;
}

int32_t main() {
   _upgrade;
   cin >> n;
   rep(i, n - 1) {
      int a;
      cin >> a;
      --a;
      G[i + 1].push_back(a);
      G[a].push_back(i + 1);
   }

   dfs(0, true);

   assert(sz(C) > 0 && sz(C) <= 2);
   int wynik = 0;
   for (int c : C) {
      dfs(c);
      int res = accumulate(S, S + n, 0ll);
      vector<int> T(n);
      for (auto a : G[c])
         T[S[a]]++;

      debug(T);

      rep(i, n) if (T[i] > 2) {
         int x = (T[i] - 2) / 2;
         T[2 * i] += x;
         T[i] -= 2 * x;
         assert(T[i] > 0);
      }

      debug(T);

      bitset<MAXN> B;
      B[0] = true;
      rep(i, n) rep(k, T[i]) B |= (B << i);
      rep(i, n) if (B[i]) wynik = max(wynik, res + i * (n - 1 - i));
   }
   cout << wynik << endl;
}