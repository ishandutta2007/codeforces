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

ostream &operator<<(ostream &out, __int128_t a) {
   if (a > (1ll << 62))
      return out << "ZA DUZY";
   else
      return out << (long long)(a);
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

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef __int128_t lll;
#define int long long

lll mod_mul(lll a, lll b, lll M) { return (a * b) % M; }

lll mod_pow(lll b, lll e, lll mod) {
   lll ans = 1;
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

const int Q = 1e9 + 7;
int P, a;

void pre() {

   int k;
   for (k = 10;; k++)
      if (isPrime(k * Q + 1)) {
         P = k * Q + 1;
         break;
      }
   for (a = 2;; a++) {
      if (mod_pow(a, Q, P) == 1 && mod_pow(a, k, P) != 1)
         break;
   }

   debug(P, a);
}

const int MAXN = 2e5 + 99;

lll tab[MAXN];
ll sum[MAXN];

lll inv(lll a, lll p) { return mod_pow(a, p - 2, p); }

lll get(int m, int d, int ile) {
   lll dile = mod_pow(a, d * ile, P) - 1;
   lll dsamo = mod_pow(a, d, P) - 1;
   lll sg = mod_mul(dile, inv(dsamo, P), P);
   return mod_mul(sg, mod_pow(a, m, P), P);
}

int32_t main() {
   _upgrade;
   int n, q;
   pre();
   cin >> n >> q;

   rep(i, n) {
      int b;
      cin >> b;

      sum[i + 1] = b;
      tab[i + 1] = mod_pow(a, b, P);

      tab[i + 1] += tab[i];
      sum[i + 1] += sum[i];
   }

   rep(i, q) {
      int l, r, d;
      cin >> l >> r >> d;
      lll s = sum[r] - sum[l - 1];
      lll ile = r - l + 1;
      s -= ile * (ile - 1) / 2 * d;
      s = (s % Q + Q) % Q;
      // pierwszy element
      lll m = mod_mul(s, mod_pow(ile, Q - 2, Q), Q);

      lll target = get(m, d, ile);
      lll hash = (tab[r] - tab[l - 1]) % P;

      cout << ((target == hash) ? "Yes" : "No") << endl;
   }
}