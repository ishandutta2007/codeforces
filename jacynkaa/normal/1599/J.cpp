#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize")
#pragma GCC target("popcnt,mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,tune=native")
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

const int MAXN = 3e6;
const int MAXK = 28;

vector<int> getp(vector<int> &Z) {

   for (int i = -MAXN; i <= MAXN; i++) {
      vector<int> Q = {i};
      rep(j, sz(Z) - 1) Q.push_back(Z[j] - Q.back());
      if (Z.back() == Q[0] + Q.back())
         return Q;
   }

   debug("HALO");
   exit(-1);
}

const int MAXT = MAXK * 1e6;
int32_t Q[MAXT];

inline int32_t nxt(int32_t x) {
   int32_t c = x & -x, r = x + c;
   return (((r ^ x) >> 2) / c) | r;
}

inline int get_sum(int S, vector<int> &X, int n) {
   int sum = 0;
   rep(i, n) if (S & (1 << i)) sum += X[i];
   return sum;
}

vector<int> get(vector<int> &X, int mask1, int mask2) {
   int n = sz(X);
   vector<int> res;
   rep(i, n) if ((mask1 & (1 << i)) && (mask2 & (1 << i)) == 0) res.push_back(X[i]);
   return res;
}

vector<int> getnp(vector<int> &X, int mask1, int mask2) {
   debug(mask1, mask2);
   vector<int> A = get(X, mask1, mask2);
   vector<int> B = get(X, mask2, mask1);
   debug(A, B);
   assert(sz(A) == sz(B));

   vector<int> res = {0};
   vector<int> Q;

   rep(i, sz(A)) {
      Q.push_back(A[i]);
      Q.push_back(B[i]);
   }
   rep(i, sz(Q) - 1) res.push_back(Q[i] - res.back());
   assert(res[0] + res.back() == Q.back());
   return res;
}

vector<int> getnp(vector<int> &X) {
   int n = sz(X);
   if (n < 4)
      return {};
   int t = n / 2;
   int32_t start = 0;
   rep(i, t) start += (1 << i);

   int S = start;

   while (true) {
      int r = get_sum(S, X, n);
      if (Q[r] != 0) {
         return getnp(X, Q[r], S);
      } else
         Q[r] = S;

      S = nxt(S);
      if (S & (1 << n))
         break;
   }
   return {};
}

vector<int> get_short(vector<int> &X) {

   vector<int> P;
   vector<int> NP;

   for (int x : X)
      if (x % 2 == 0)
         P.push_back(x);
      else
         NP.push_back(x);

   if (sz(P) >= 3) {
      P.resize(3);
      return getp(P);
   } else if (sz(P) >= 1 && sz(NP) >= 2) {
      vector<int> T = {P[0], NP[0], NP[1]};
      return getp(T);
   } else {
      random_shuffle(all(NP));
      NP.resize(min(sz(NP), MAXK));
      return getnp(NP);
   }
}

void add(vector<int> &res, set<int> &S, int a) {
   for (auto b : res)
      S.insert(a + b);
   res.push_back(a);
}

vector<int> get_all(vector<int> shor, vector<int> X) {
   debug(shor);
   vector<int> res;
   set<int> S;
   for (int a : shor)
      add(res, S, a);

   for (int x : X)
      if (S.find(x) == S.end())
         add(res, S, x - res[0]);

   assert(sz(res) <= sz(X));
   while (sz(res) != sz(X))
      res.push_back(0);

   return res;
}

void pre() {
   vector<int> X = {};
   rep(i, 30) X.push_back((1 << i) + 1);
   X[0]--;
   for (auto x : X)
      cerr << x << " ";
   cerr << endl;
}

int32_t main() {
   // pre();

   _upgrade;
   int n;
   cin >> n;
   vector<int> X(n);
   rep(i, n) cin >> X[i];

   debug(X);

   map<int, int> M;
   for (auto x : X)
      M[x]++;

   int f = -1;
   for (auto [a, b] : M) {
      if (b > 1) {
         f = a;
         break;
      }
   }

   vector<int> shor;

   if (f != -1) {
      shor = {0, f};
   } else {
      shor = get_short(X);
   }

   if (sz(shor)) {
      auto res = get_all(shor, X);
      cout << "YES\n";
      for (auto a : res)
         cout << a << " ";
      cout << endl;
   } else {
      cout << "NO\n";
   }
}