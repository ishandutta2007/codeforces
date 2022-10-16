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

string get(vector<string> D) {
   string res = D[0];
   for (auto s : D)
      if (sz(s) != sz(res)) {
         cout << "No\n";
         exit(0);
      } else
         rep(i, sz(s)) if (s[i] != res[i]) res[i] = '?';
   return res;
}

bool diff(string S, string T) {
   if (sz(S) != sz(T))
      return true;
   rep(i, sz(S)) if (S[i] != T[i] && T[i] != '?') return true;
   return false;
}

int32_t main() {
   _upgrade;
   int m, n;
   cin >> m >> n;
   vector<string> A(m);
   rep(i, m) cin >> A[i];
   vector<string> D;
   set<int> S;

   rep(j, n) {
      int i;
      cin >> i;
      S.insert(--i);
      D.push_back(A[i]);
   }

   debug(S, D);

   auto T = get(D);
   debug(T);

   rep(i, sz(A)) if (S.count(i) == 0) if (!diff(A[i], T)) {
      cout << "No\n";
      exit(0);
   }
   cout << "Yes" << endl;
   cout << T << endl;
}