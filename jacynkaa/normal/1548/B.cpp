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
#define debug(...) 42
#endif

#define int long long

template <class T> struct RMQ {
   vector<vector<T>> jmp;
   RMQ(const vector<T> &V) {
      int N = sz(V), on = 1, depth = 1;
      while (on < N)
         on *= 2, depth++;
      jmp.assign(depth, V);
      fwd(i, 0, depth - 1) fwd(j, 0, N) jmp[i + 1][j] = __gcd(jmp[i][j], jmp[i][min(N - 1, j + (1 << i))]);
   }

   T query(int a, int b) {
      assert(a < b); // or return i n f i f a == b
      int dep = 31 - __builtin_clz(b - a);
      return __gcd(jmp[dep][a], jmp[dep][b - (1 << dep)]);
   }
};

bool check(RMQ<int> &rmq, int s, int N) {
   if (s == 0)
      return true;
   //  debug(s, N);
   rep(i, N) if (i + s <= N && rmq.query(i, i + s) > 1) { return true; }
   return false;
}

int get(vector<int> Y) {

   debug(Y);

   int N = sz(Y);
   int p = 0;
   int q = N;

   RMQ<int> rmq(Y);

   while (p < q) {
      debug(p, q);
      int s = (p + q + 1) / 2;
      if (check(rmq, s, N))
         p = s;
      else
         q = s - 1;
   }
   return q;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      int n;
      cin >> n;
      vector<int> X(n);
      rep(i, n) cin >> X[i];
      vector<int> Y;
      rep(i, n - 1) Y.push_back(abs(X[i] - X[i + 1]));
      cout << get(Y) + 1 << endl;
   }
}