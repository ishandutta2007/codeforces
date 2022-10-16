#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
// mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
// struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
// gp_hash_table<long long, int, custom_hash> safe_hash_table; -szybsza hashmapa

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
#define debug(...)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     \
   if (false)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \
   cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;

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

#define int long long

void wypisz(multiset<int> &opcjonalne, multiset<int> &obowiazkowe, int k) {
   debug(opcjonalne, obowiazkowe);
   k -= sz(obowiazkowe);
   for (int a : obowiazkowe)
      cout << a << " ";
   for (int b : opcjonalne) {
      if (k-- > 0)
         cout << b << " ";
   }
   cout << endl;
   exit(0);
}

void wrzucP(multiset<int> &opcjonalne, multiset<int> &obowiazkowe, map<int, vector<int>> &primes, int p) {
   rep(i, sz(primes[p])) {
      if (i < 2)
         obowiazkowe.insert(primes[p][i]);
      else
         opcjonalne.insert(primes[p][i]);
   }
}

int32_t main() {
   _upgrade;
   int n, k;
   cin >> n >> k;
   map<int, vector<int>> primes;
   map<vector<ull>, vector<int>> others;

   rep(i, n) {
      int a;
      cin >> a;
      auto V = factor(a);
      sort(all(V));
      V.erase(unique(all(V)), V.end());
      if (sz(V) == 1)
         primes[V[0]].push_back(a);
      else {
         others[V].push_back(a);
      }
   }

   vector<int> remP;
   int trzy = -1;
   for (auto &p : primes) {

      if (sz(p.nd) == 1)
         remP.push_back(p.st);

      if (sz(p.nd) > 2)
         trzy = p.st;
   }

   for (auto p : remP)
      primes.erase(p);

   map<vector<ull>, vector<int>> tmp;
   vector<ull> minimalny(1e6);

   debug(others, primes);
   for (auto V : others) {

      bool OK = true;
      for (auto v : V.st) {
         if (primes.find(v) == primes.end()) {
            OK = false;
         }
      }

      if (OK) {
         tmp[V.st] = V.nd;
         if (sz(minimalny) > sz(V.st))
            minimalny = V.st;
      }
   }

   others = tmp;

   debug(primes, others, k);

   if (k == 1 || (k % 2 == 1 && trzy == -1 && k < 2 * sz(minimalny))) {
      debug("DUZY");
      cout << 0 << endl;
      exit(0);
   }

   multiset<int> obowiazkowe;
   multiset<int> opcjonalne;

   if (trzy != -1) {
      wrzucP(opcjonalne, obowiazkowe, primes, trzy);
      primes.erase(trzy);
   } else if (k % 2 == 1) {
      for (auto v : minimalny) {
         wrzucP(opcjonalne, obowiazkowe, primes, v);
         primes.erase(v);
      }
      for (int a : others[minimalny])
         opcjonalne.insert(a);
      others.erase(minimalny);
   }

   for (auto p : primes) {
      if (sz(opcjonalne) + sz(obowiazkowe) >= k)
         break;
      wrzucP(opcjonalne, obowiazkowe, primes, p.st);
   }

   if (sz(opcjonalne) + sz(obowiazkowe) >= k)
      wypisz(opcjonalne, obowiazkowe, k);

   for (auto v : others)
      for (auto a : v.nd)
         opcjonalne.insert(a);
   if (sz(opcjonalne) + sz(obowiazkowe) >= k)
      wypisz(opcjonalne, obowiazkowe, k);
   else {
      cout << 0 << endl;
   }
}