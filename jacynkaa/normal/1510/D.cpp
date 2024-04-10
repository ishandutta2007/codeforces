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
#define debug(...)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     \
   {}
#endif

typedef vector<vector<int>> vii;
typedef unsigned __int128 uint128_t;
typedef uint128_t lll;

int ile[] = {4, 1, 4, 4, 2, 4, 1, 4, 4, 2};
const int M = 10;
const lll inf = 1e35;

int get(vii &X) {
   int p = 1;
   rep(i, M) rep(k, sz(X[i])) p = (p * i) % M;
   return p;
}

void add(vector<int> &res, vii X) {
   for (auto x : X)
      for (int a : x)
         res.push_back(a);
}

lll mul(lll a, lll x) {
   if (a > inf)
      return inf;
   return a * x;
}

vii best(vii A, vii B) {
   if (sz(B) == 0)
      return A;
   if (sz(A) == 0)
      return B;

   lll a = 1;
   lll b = 1;
   rep(i, M) {
      for (int k = sz(B[i]); k < sz(A[i]); k++)
         a = mul(a, A[i][k]);
      for (int k = sz(A[i]); k < sz(B[i]); k++)
         b = mul(b, B[i][k]);
   }
   return a > b ? A : B;
}

vector<vii> sub(vii X) {
   vector<vii> res = {vii(M)};

   rep(i, M) {
      vii Q;
      for (int k = 0; k < sz(X[i]); k++)
         Q.emplace_back(X[i].begin(), X[i].begin() + k + 1);

      int s = sz(res);
      for (auto q : Q) {
         rep(j, s) {
            auto x = res[j];
            x[i] = q;
            res.push_back(x);
         }
      }
   }
   return res;
}

void koniec(int m) {
   cout << m << endl;
   exit(0);
}

void koniec(vector<int> &res) {
   if (sz(res) == 0)
      koniec(-1);
   cout << sz(res) << endl;
   for (int a : res)
      cout << a << " ";
   cout << endl;
   exit(0);
}

int32_t main() {
   _upgrade;

   vii X(M);
   int n, d;
   cin >> n >> d;
   rep(i, n) {
      int a;
      cin >> a;
      X[a % M].push_back(a);
   }

   vector<int> res;

   rep(i, M) sort(all(X[i]));

   if (d == 0) {
      int r = get(X);
      if (r == 0)
         add(res, X);
      koniec(res);
   }

   if (d == 5) {
      rep(i, 5) X[i * 2].clear();
      int r = get(X);
      if (r == 5)
         add(res, X);
      koniec(res);
   }

   if (d % 2 == 1) {
      rep(i, 5) X[i * 2].clear();
      X[5].clear();
   } else {
      X[5].clear();
      X[0].clear();
   }

   debug(X);

   vii Xp(M);

   rep(i, M) {
      Xp[i] = vector<int>(X[i].begin(), X[i].begin() + min(ile[i], sz(X[i])));
      X[i].erase(X[i].begin(), X[i].begin() + min(ile[i], sz(X[i])));
      reverse(all(Xp[i]));
   }

   debug(Xp);

   auto dp = get(X);
   add(res, X);
   X = Xp;

   vii B = {};
   auto T = sub(X);
   debug(T);

   for (auto t : T)
      if ((get(t) * dp) % 10 == d) {
         B = best(B, t);
      }
   debug(B);

   if (sz(B) == 0)
      koniec(-1);
   else {
      add(res, B);
      koniec(res);
   }
}