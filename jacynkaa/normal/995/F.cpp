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

constexpr int MOD = 1e9 + 7;
// Some big prime: 15*(1<<27)+1 ~ 2*10^9

ll modInv(ll a, ll m) { // a^(-1) mod m
   if (a == 1)
      return 1;
   return ((a - modInv(m % a, a)) * m + 1) / a;
}

ll modPow(ll a, ll e, ll m) { // a^e mod m
   ll t = 1 % m;
   while (e) {
      if (e % 2)
         t = t * a % m;
      e /= 2;
      a = a * a % m;
   }
   return t;
}

// Wrapper for modular arithmetic
//! Warning: we need to keep it binary compatible with `ll` type here,
//! because we cast vector<Zp> as vector<ll> in `polynomial.h`.
struct Zp {
   ll x; // Contained value, in range [0;MOD-1]
   Zp() : x(0) {}
   Zp(ll a) : x(a % MOD) {
      if (x < 0)
         x += MOD;
   }

#define OP(c, d)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       \
   Zp &operator c##=(Zp r) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           \
      x = x d;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         \
      return *this;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    \
   }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   \
   Zp operator c(Zp r) const {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         \
      Zp t = *this;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    \
      return t c## = r;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                \
   }

   OP(+, +r.x - MOD * (x + r.x >= MOD));
   OP(-, -r.x + MOD * (0 > x - r.x));
   OP(*, *r.x % MOD);
   OP(/, *r.inv().x % MOD);
   Zp operator-() const { return Zp() - *this; }

   // For composite modulus use modInv, not pow
   Zp inv() const { return pow(MOD - 2); }
   Zp pow(ll e) const { return modPow(x, e, MOD); }
};

ostream &operator<<(ostream &out, Zp x) { return out << x; }

// Interpolate set of points (i, vec[i])
// and return it evaluated at x; time: O(n)
template <class T> T polyExtend(vector<T> &vec, T x) {
   int n = sz(vec);
   vector<T> fac(n, 1), suf(n, 1);

   fwd(i, 1, n) fac[i] = fac[i - 1] * i;
   for (int i = n; --i;)
      suf[i - 1] = suf[i] * (x - i);

   T pref = 1, ret = 0;
   fwd(i, 0, n) {
      T d = fac[i] * fac[n - i - 1] * ((n - i) % 2 * 2 - 1);
      ret += vec[i] * suf[i] * pref / d;
      pref *= x - i;
   }
   return ret;
}

const int MAXD = 3002;

typedef vector<Zp> vz;
vector<int> G[MAXD];
int n, d;

void combine(vz &a, vz b) { rep(i, sz(b)) a[i] *= b[i]; }
void pref(vz &a) {
   for (int i = 1; i < sz(a); i++)
      a[i] += a[i - 1];
}

vz dfs(int x) {
   vz res(n + 3, {1});
   for (int y : G[x])
      combine(res, dfs(y));
   pref(res);
   return res;
}

int32_t main() {
   _upgrade;
   cin >> n >> d;

   rep(i, n - 1) {
      int a;
      cin >> a;
      G[--a].push_back(i + 1);
   }
   auto r = dfs(0);
   auto res = polyExtend(r, {d - 1});
   cout << res.x << endl;
}