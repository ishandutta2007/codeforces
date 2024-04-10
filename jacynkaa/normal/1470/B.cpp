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
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define SIZE(X) (int)((X).size())
#define ALL(X) (X).begin(), (X).end()
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
 
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
 
const int MAXN = 2e6;
 
int D[MAXN];
 
void pre() {
   for (int i = 2; i < MAXN; i++) {
      if (D[i] == 0)
         for (int j = i; j < MAXN; j += i)
            D[j] = i;
   }
}
 
vector<int> decompose(int x) {
   map<int, int> M;
   while (x > 1) {
      M[D[x]]++;
      x /= D[x];
      // debug(x);
   }
   vector<int> Q;
   for (auto m : M)
      if (m.nd % 2 != 0)
         Q.push_back(m.st);
 
   sort(all(Q));
   return Q;
}
 
int32_t main() {
    _upgrade;
   int Z;
   cin >> Z;
   pre();
   while (Z--) {
      int n;
      cin >> n;
      map<vector<int>, int> M;
 
      rep(i, n) {
         int x;
         cin >> x;
         M[decompose(x)]++;
      }
      debug(M);
 
      int zero1 = M[vector<int>()];
      int zero2 = zero1;
      M.erase(vector<int>());
 
      int res1 = 0;
      int res2 = 0;
      for (auto m : M) {
         if (m.nd % 2 != 0) {
            res1 = max(res1, m.nd);
            res2 = max(res2, m.nd);
         } else {
            res1 = max(res1, m.nd);
            zero2 += m.nd;
         }
      }
 
      debug(res1, res2, zero1, zero2);
 
      int q;
      cin >> q;
      while (q--) {
         int a;
         cin >> a;
         if (a == 0)
            cout << max(res1, zero1) << endl;
         else
            cout << max(res2, zero2) << endl;
      }
   }
}