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

typedef tuple<pii, int, int> tpl;

typedef map<tpl, vector<pii>> Res;

struct MINE {

   Res res;
   vector<set<pii>> S;
   vector<int> kapitan;

   int fiind(int x) { return x == kapitan[x] ? x : kapitan[x] = fiind(kapitan[x]); }

   void mer(tpl p) {
      auto [_, a, b] = p;
      int y = fiind(a);
      int x = fiind(b);

      if (x == y)
         return;

      res[p] = {};

      if (sz(S[x]) < sz(S[y]))
         swap(x, y);
      kapitan[y] = x;

      for (auto i : S[y])
         if (S[x].find(i) != S[x].end()) {
            res[p].push_back(i);
            S[x].erase(i);
         } else
            S[x].insert(i);
   }

   Res solve(int n, vector<tpl> E, vector<pii> P) {
      sort(all(E));

      S.resize(n);
      rep(i, n) kapitan.push_back(i);

      rep(i, sz(P)) {
         auto [a, b] = P[i];
         S[a].insert({a, b});
         S[b].insert({a, b});
      }

      for (auto t : E)
         mer(t);

      return res;
   }
}; // namespace MINE

struct MER {

   vector<int> kapitan1, kapitan2;
   vector<int> R;
   vector<vector<int>> S;
   vector<tpl> res;
   map<pii, int> M;

   int fiind(int x, vector<int> &kapitan) { return x == kapitan[x] ? x : kapitan[x] = fiind(kapitan[x], kapitan); }

   void unia(int a, int b, pii p) {
      int x = fiind(a, kapitan2);
      int y = fiind(b, kapitan2);
      if (x == y)
         return;

      kapitan2[y] = x;
      R[x] += R[y];
      res.push_back({p, x, y});
   }

   void mer(int a, int b, pii p) {
      int x = fiind(a, kapitan1);
      int y = fiind(b, kapitan1);
      debug(a, b);

      assert(x != y);

      vector<pii> T;
      for (auto s1 : S[x])
         for (auto s2 : S[y]) {
            long long r = (ll)(R[s1]) * (ll)(R[s2]) - M[minmax(s1, s2)];
            if (r)
               T.push_back({s1, s2});
         }

      for (auto [s1, s2] : T)
         unia(s1, s2, p);

      vector<int> ST;
      for (auto s1 : S[x])
         if (kapitan2[s1] == s1)
            ST.push_back(s1);
      for (auto s1 : S[y])
         if (kapitan2[s1] == s1)
            ST.push_back(s1);
      kapitan1[y] = x;
      S[x] = ST;
   }

   vector<tpl> solve(int n, Res E) {
      rep(i, n) kapitan1.push_back(i);
      kapitan2 = kapitan1;
      rep(i, n) R.push_back(1);
      rep(i, n) S.push_back({i});

      for (auto [t, P] : E) {
         M.clear();
         auto [p, a, b] = t;

         for (auto [x, y] : P)
            M[minmax(fiind(x, kapitan2), fiind(y, kapitan2))]++;

         mer(a, b, p);
      }
      return res;
   }
};

void solve() {
   int n, m;
   cin >> n >> m;
   vector<tpl> E;
   vector<pii> P;

   rep(i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      P.push_back({--a, --b});
      E.push_back({{c, i}, a, b});
   }

   MINE M1, M2;
   MER ME;

   auto res = M1.solve(n, E, P);

   debug(res);

   auto s8 = ME.solve(n, res);

   auto wynik = M2.solve(n, s8, P);

   map<pii, int> M;
   for (auto [t, P] : wynik) {
      auto [p, _, __] = t;
      for (auto q : P)
         M[q] = p.st;
   }

   for (auto q : P)
      cout << M[q] << " ";
   cout << endl;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}