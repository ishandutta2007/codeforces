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

const int T = 5;
vector<string> S;
int n;

template <class T> T mod(const T &Q, T &res, int r) {
   // debug(r, sz(Q), sz(res));
   rep(i, sz(Q)) res[i] = Q[i ^ r];
   return res;
}

vector<string> split(string Q) {
   vector<string> res = {""};
   rep(i, sz(Q)) {
      if (res.back().size() == 1 << T)
         res.push_back("");
      res.back().push_back(Q[i]);
   }
   // debug(res);
   return res;
}

void mini(vector<int> &A, vector<int> &B) {
   rep(i, sz(A)) if (B[i] != A[i]) {
      if (A[i] > B[i])
         swap(A, B);
      return;
   }
}

int32_t main() {
   _upgrade;
   cin >> n;
   // n = 18;
   string Q, P;
   cin >> Q;
   // rep(i, 1 << n) Q.push_back('a' + rand() % 23);
   P = Q;

   rep(i, 1 << min(T, n)) {
      mod(Q, P, i);
      auto X = split(P);
      for (auto x : X)
         S.push_back(x);
   }

   sort(all(S));
   S.erase(unique(all(S)), S.end());
   // debug(S);

   vector<int> res;

   rep(i, 1 << min(T, n)) {
      mod(Q, P, i);
      auto U = split(P);
      vector<int> tmp;
      for (auto x : U)
         tmp.push_back(lower_bound(all(S), x) - S.begin());
      vector<int> cur = tmp;
      if (sz(res) == 0)
         res = tmp;

      rep(i, 1 << max(0, n - T)) {
         //  debug(i);
         auto y = mod(tmp, cur, i);
         mini(res, y);
      }
   }

   for (auto r : res)
      cout << S[r];
   cout << endl;
}