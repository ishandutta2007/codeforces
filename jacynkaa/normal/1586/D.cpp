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

// vector<int> P;
// int N;

// void pre() {
//    P.clear();
//    rep(i, N) P.push_back(i + 1);
//    random_shuffle(all(P));
//    debug(P);
// }

int get(vector<int> &X) {
   // assert(sz(X) == N);
   // map<int, int> M;
   // rep(i, N) M[X[i] + P[i]]++;
   // rep(i, N) if (M[X[i] + P[i]] > 1) return i + 1;
   // return 0;

   cout << "? ";
   for (int x : X)
      cout << x << " ";
   cout << endl;
   int a;
   cin >> a;
   return a;
}

void ans(vector<int> &X) {
   debug(X);

   set<int> S(all(X));
   assert(sz(X) == sz(S));
   assert(*min_element(all(X)) == 1 && *max_element(all(X)) == sz(X));

   assert(get(X) == 0);
   cout << "! ";
   for (int x : X)
      cout << x << " ";
   cout << endl;
}

int32_t main() {

   // for (N = 2; N <= 100; N++) {
   int n;
   // n = N;
   // pre();
   cin >> n;

   int last = 1;

   for (int i = 1; i <= n - 1; i++) {
      vector<int> X(n, n);
      X.back() = i;
      if (get(X) != 0) {
         last = n - i + 1;
         break;
      }
   }

   debug(last);

   vector<int> res(n, last);

   for (int i = 1; i <= n; i++) {
      if (i != last) {
         vector<int> X(n, last);
         X.back() = i;
         auto k = get(X);
         debug(k);
         res[k - 1] = i;
      }
   }
   debug(res);
   ans(res);
   //}
}