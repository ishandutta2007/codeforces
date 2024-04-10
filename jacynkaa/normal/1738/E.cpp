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

const ll mod = 998244353;

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

ull mod_mul(ull a, ull b) { return mod_mul(a, b, mod); }
ull mod_pow(ull a, ull b) { return mod_pow(a, b, mod); }
ull inv(ull a) { return mod_pow(a, mod - 2, mod); }

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

const int MAXF = 5e5;
ll F[MAXF], I[MAXF];
ll pot[MAXF];

void pre() {
   F[0] = I[0] = pot[0] = 1;
   for (int i = 1; i < MAXF; i++) {
      F[i] = mod_mul(i, F[i - 1]);
      I[i] = inv(F[i]);
      pot[i] = (2 * pot[i - 1]) % mod;
   }
}
ll binom(int a, int b) { return mod_mul(mod_mul(F[a], I[b]), I[a - b]); }

void solve() {
   int n;
   cin >> n;
   deque<int> D(n);
   rep(i, n) cin >> D[i];

   if (count(all(D), 0) == n) {
      cout << pot[n - 1] << endl;
      return;
   }

   deque<pii> A;
   int c = 0;
   bool srodek = false;

   while (sz(D)) {
      int a = 0, b = 0;
      while (sz(D) && D[0] == 0) {
         D.pop_front();
         a++;
      }
      while (sz(D) && D.back() == 0) {
         D.pop_back();
         b++;
      }
      if (sz(D))
         A.push_back({a, b});
      else
         c = a + b;

      if (sz(D)) {
         int a = D[0];
         D.pop_front();
         int b = 0;
         while (sz(D) && a != b) {
            if (a > b) {
               b += D.back();
               D.pop_back();
            } else {
               a += D.front();
               D.pop_front();
            }
         }
         if (a == b) {
            srodek = true;
         } else {
            srodek = false;
         }
      }
   }

   debug(A);
   debug(c, srodek);

   int res = 1;
   rep(i, sz(A)) {
      auto [a, b] = A[i];
      if (i != 0)
         a++, b++;
      int sum = 0;
      rep(i, min(a, b) + 1) { sum += (binom(a, i) * binom(b, i)) % mod; }
      sum %= mod;
      debug(sum);
      res = mod_mul(sum, res);
   }

   if (srodek)
      c++;

   res = mod_mul(res, pot[c]);
   cout << res << endl;
}

int32_t main() {
   pre();
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}