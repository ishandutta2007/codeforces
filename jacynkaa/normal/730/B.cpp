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

char get(int i, int j) {
   cout << "? " << i << " " << j << endl;
   char c;
   cin >> c;
   return c;
}

void ans(int i, int j) { cout << "! " << i << " " << j << endl; }

int solve(vector<int> A, char c) {
   int r = A[0];
   for (int i = 1; i < sz(A); i++)
      if (get(r, A[i]) == c)
         r = A[i];
   return r;
}

void solve() {
   int n;
   cin >> n;
   vector<int> X;
   rep(i, n) X.push_back(i + 1);

   vector<int> A, B;
   while (sz(X) > 1) {

      int a = X.back();
      X.pop_back();
      int b = X.back();
      X.pop_back();

      char c = get(a, b);
      if (c != '>')
         A.push_back(a), B.push_back(b);
      else
         A.push_back(b), B.push_back(a);
   }
   if (sz(X))
      A.push_back(X[0]), B.push_back(X[0]);

   debug(A, B);

   int a = solve(A, '>');
   int b = solve(B, '<');
   ans(a, b);
}

int32_t main() {
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}