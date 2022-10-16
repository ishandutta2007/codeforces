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

ull mod_mul(ull a, ull b, ull M) {
   ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
   return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull mod_pow(ull b, ull e, ull mod) {
   ull ans = 1;
   for (; e; b = mod_mul(b, b, mod), e /= 2)
      if (e & 1)
         ans = mod_mul(ans, b, mod);
   return ans;
}

ull pollard(ull n) {
   auto f = [n](ull x) { return (mod_mul(x, x, n) + 1) % n; };
   if (!(n & 1))
      return 2;
   for (ull i = 2;; i++) {
      ull x = i, y = f(x), p;
      while ((p = __gcd(n + y - x, n)) == 1)
         x = f(x), y = f(f(y));
      if (p != n)
         return p;
   }
}

bool isPrime(ull n) {
   if (n < 2 || n % 6 % 4 != 1)
      return n - 2 < 2;
   ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_ctzll(n - 1), d = n >> s;
   for (int a : A) {
      ull p = mod_pow(a, d, n), i = s;
      while (p != 1 && p != n - 1 && a % n && i--)
         p = mod_mul(p, p, n);
      if (p != n - 1 && i != s)
         return 0;
   }
   return 1;
}

vector<ull> factor(ull n) {
   if (n == 1)
      return {};
   if (isPrime(n))
      return {n};
   ull x = pollard(n);
   auto l = factor(x), r = factor(n / x);
   l.insert(l.end(), all(r));
   return l;
}

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 99;
int inv(int a) { return mod_pow(a, mod - 2, mod); }
int mod_mul(int a, int b) { return mod_mul(a, b, mod); }

int F[MAXN + 2];
int I[MAXN + 2];

void pre() {
   F[0] = 1;
   rep(i, MAXN) F[i + 1] = (F[i] * (i + 1)) % mod;
   rep(i, MAXN) I[i] = inv(F[i]);
}

int32_t main() {
   _upgrade;
   pre();
   int n, k;
   cin >> n >> k;
   vector<int> val(k + 2);

   for (int i = 1; i < sz(val); i++)
      val[i] = (val[i - 1] + mod_pow(i, k, mod)) % mod;

   if (n < sz(val)) {
      cout << val[n] << "\n";
      exit(0);
   }

   int mult = 1;
   rep(i, sz(val)) mult = (mult * (n - i)) % mod;

   debug(mult);

   int res = 0;

   rep(i, sz(val)) {
      int a = i;
      int b = sz(val) - i - 1;
      int mn = (I[a] * I[b]) % mod;
      if (b & 1)
         mn = (mn * (mod - 1)) % mod;

      res += mod_mul(mod_mul(mn, mult), mod_mul(inv(n - i), val[i])); //(((mn * mult) % mod) * inv(n - i)) % mod;
   }
   cout << res % mod << endl;
}