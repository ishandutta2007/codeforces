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
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> distr(1e13, 1e14);
auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
// struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
// gp_hash_table<long long, int, custom_hash> safe_hash_table; -szybsza hashmapa

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

#define int long long

const int MAXM = 1e14;
const int MAXILE = 105;
int ile = 0;
const int L = 35184372088832LL;

bool ask(int x) {
   ile++;
#ifdef LOCAL
   return x <= L;
#endif
   cout << "? " << x << endl;
   string S;
   cin >> S;
   if (S == "Fired!")
      exit(-1);
   return S[0] == 'L';
}

void ans(int x) { cout << "! " << x << endl; }

int32_t main() {
   int Z;

   cin >> Z;
   while (Z--) {
      debug(MAXM);
      int p = 0;
      int q = MAXM;
      int kasa = 1;

      int alpha = 670;
      int Q = 1000;
      while (p != q) {
         int s;

         if (kasa > 2 * q)
            s = (p + q + 1) / 2;
         else
            s = (alpha * p + (Q - alpha) * q + (Q - 1)) / Q;

         if (kasa < s)
            s = max(p, kasa);

         bool OK = ask(s);
         if (OK) {
            kasa += s;
            p = s;
         } else {
            kasa -= s;
            q = s - 1;
         }
      }
      debug(ile);
      ans(p);
   }
}