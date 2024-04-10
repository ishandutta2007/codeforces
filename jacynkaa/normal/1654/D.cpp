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

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

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

const int MAXN = 2e5 + 99;
vector<int> R[MAXN];

void pre() {
   for (int i = 2; i < MAXN; i++)
      if (sz(R[i]) == 0)
         for (int j = i; j < MAXN; j += i)
            R[j].push_back(i);
}

vector<int> factor(int x) {
   vector<int> res;
   for (int p : R[x]) {
      while (x % p == 0) {
         res.push_back(p);
         x /= p;
      }
   }
   return res;
}

typedef tuple<int, int, int> tpl;

vector<tpl> G[MAXN];

int wynik = 0;
map<int, int> C;
map<int, int> res;

int get(int a, int b) { return mod_mul(mod_pow(a, mod - 2, mod), b, mod); }

void dfs(int x, int p = -1, int cur = 1) {
   wynik += cur;

   debug(x, cur);

   for (auto [y, a, b] : G[x])
      if (y != p) {
         auto A = factor(a);
         auto B = factor(b);
         swap(A, B);
         for (int x : A)
            C[x]++;
         for (int x : B) {
            C[x]--;
            res[x] = min(res[x], C[x]);
         }

         debug(C);

         auto tmp = mod_mul(get(a, b), cur, mod);

         dfs(y, x, tmp);

         for (int x : A)
            C[x]--;
         for (int x : B)
            C[x]++;
      }
}

void solve() {
   int n;
   cin >> n;
   rep(i, n - 1) {
      int x, y, a, b;
      cin >> x >> y >> a >> b;
      int g = __gcd(a, b);
      a /= g;
      b /= g;
      G[--x].push_back({--y, a, b});
      G[y].push_back({x, b, a});
   }

   dfs(0);

   debug(wynik, res);
   wynik %= mod;

   for (auto [p, b] : res)
      if (b < 0)
         rep(i, abs(b)) wynik = mod_mul(wynik, p, mod);

   cout << wynik << endl;

   wynik = 0;
   rep(i, n) G[i].clear();
   C.clear();
   res.clear();
}

int32_t main() {
   _upgrade;
   pre();
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}