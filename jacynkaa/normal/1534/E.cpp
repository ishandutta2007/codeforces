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

int n, k;

pair<bool, vector<vector<int>>> OK(set<pii> S, int R) {

   int l = R / k;
   if (S.rbegin()->st > l)
      return {false, {}};

   vector<vector<int>> res;

   while (sz(S) >= k) {
      vector<pii> T;
      vector<int> Q;

      auto itr = S.end();
      rep(i, k) T.push_back(*(--itr));

      for (auto t : T) {
         S.erase(t);
         if (t.st - 1 > 0)
            S.insert({t.st - 1, t.nd});
         Q.push_back(t.nd);
      }
      res.push_back(Q);
   }

   // assert(sz(S) == 0);
   debug(S);

   if (sz(S) == 0)
      return {true, res};
   else
      return {false, {}};
}

// vector<int> X = {2, 1, 7, 5, 6};

void ans(vector<vector<int>> &T) {
   int res = 0;
   for (auto t : T) {
      cout << "? ";
      for (int a : t)
         cout << a + 1 << " ";
      cout << endl;

      int k = 0;
      // for (int a : t)
      //    k ^= X[a];
      // debug(k);
      cin >> k;
      res ^= k;
   }

   cout << "! " << res << endl;
   exit(0);
}

int32_t main() {
   cin >> n >> k;

   set<pii> S;
   rep(i, n) S.insert({1, i});
   int R = n;

   while (R <= 500 * k) {
      debug(R);
      if (R % k == 0) {
         auto [ok, T] = OK(S, R);
         if (ok)
            ans(T);
      }

      auto t = *S.begin();
      S.erase(t);
      S.insert({t.st + 2, t.nd});
      R += 2;
   }

   cout << -1 << endl;
}