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
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
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
      int n, m;
      cin >> n >> m;
      vector<vector<int>> X(m);
      vector<int> ile(n + 1);
      vector<int> res(m);
      rep(i, m) {
         int k;
         cin >> k;
         vector<int> Q(k);
         rep(j, k) cin >> Q[j];
         X[i] = Q;
         res[i] = Q[0];
         ile[Q[0]]++;
      }

      auto idx = max_element(all(ile)) - ile.begin();

      debug(res, ile, idx);

      bool found = false;

      rep(i, m) {

         if (ile[idx] <= ((m + 1) / 2)) {

            cout << "YES\n";
            for (int a : res)
               cout << a << " ";
            cout << endl;

            found = true;
            break;
         }
         if (X[i][0] == idx) {
            res[i] = X[i].back();
            ile[idx]--;
            ile[res[i]]++;
         }

         if (ile[idx] <= ((m + 1) / 2)) {

            cout << "YES\n";
            for (int a : res)
               cout << a << " ";
            cout << endl;
            found = true;
            break;
         }
      }

      debug(res, ile);
      if (!found) {
         cout << "NO\n";
      }
   }
}