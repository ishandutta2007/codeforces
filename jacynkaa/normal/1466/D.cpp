#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
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

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      int n;
      cin >> n;
      vector<int> W(n);
      rep(i, n) cin >> W[i];
      map<pii, int> M;
      rep(i, n - 1) {
         int a, b;
         cin >> a >> b;
         --a;
         --b;
         M[{W[a], a}]++;
         M[{W[b], b}]++;
      }

      int res = 0;
      for (auto m : M) {
         res += m.st.st * m.nd;
      }
      vector<int> R = {res};
      rep(i, n - 2) {
         // debug(M);
         while (M.begin()->nd == 1)
            M.erase(M.begin());
         res -= M.begin()->st.st;
         M.begin()->nd--;
         R.push_back(res);
      }
      reverse(all(R));
      for (int r : R)
         cout << r << " ";
      cout << endl;
   }
}