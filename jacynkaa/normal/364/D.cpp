#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#pragma GCC optimize("Ofast")
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

struct CN {
   vector<int> X;
   vector<int> D;
   int k;

   CN(vector<int> &D) : D(D), k(sz(D)) {
      X.resize(sz(D));
      sort(all(D));
   }

   int &get(int x) {
      // debug(x);
      return X[lower_bound(all(D), x) - D.begin()];
   }

   void add(int a) { get(a)++; }

   int get(set<int> P, int target) {
      for (auto p : P) {
         for (int i = k - 1; i >= 0; i--)
            if (D[i] % p == 0)
               get(D[i] / p) += X[i];
      }
      int res = 0;
      rep(i, k) if (X[i] >= target) res = D[i];
      return res;
   }
};

int n;

void brut(vector<int> X, int target) {
   int ans = 1;
   rep(S, 1 << n) if (__builtin_popcountll(S) >= target) {
      int g = 0;
      rep(i, n) if (S & (1 << i)) g = gcd(g, X[i]);
      ans = max(ans, g);
   }
   cout << ans << endl;
   exit(0);
}

const int D = 12;

tuple<vector<int>, set<int>> add(int x) {
   set<int> S;
   set<int> P;
   for (int i = 1; i * i <= x; i++)
      if (x % i == 0) {
         S.insert(i);
         S.insert(x / i);
      }

   for (int i = 2; i * i <= x; i++) {
      while (x % i == 0) {
         x /= i;
         P.insert(i);
      }
   }
   if (x > 1)
      P.insert(x);

   return {vector<int>(all(S)), P};
}

int32_t main() {
   _upgrade;
   srand(time(0));
   cin >> n;
   int target = (n + 1) / 2;
   vector<int> X(n);
   rep(i, n) cin >> X[i];
   if (n < D)
      brut(X, target);

   mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
   shuffle(all(X), rng);
   int res = 0;

   rep(i, D) {
      auto [T, P] = add(X[i]);
      debug(T, P);
      CN C(T);
      rep(j, n) C.add(__gcd(X[j], X[i]));
      res = max(C.get(P, target), res);
   }
   cout << res << endl;
}