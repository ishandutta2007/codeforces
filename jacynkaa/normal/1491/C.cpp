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

const int MAXN = 5009;

void solve() {
   int n;
   cin >> n;
   vector<int> S(n);
   rep(i, n) cin >> S[i];
   set<int> NJ;
   rep(i, n) if (S[i] != 1) NJ.insert(i);
   NJ.insert(MAXN);

   debug(NJ);

   int res = 0;

   int idx = 0;
   while (idx < n) {
      if (S[idx] == 1) {
         idx++;
         continue;
      }
      if (S[idx] > MAXN) {
         res += S[idx] - MAXN;
         S[idx] = MAXN;
      }
      res++;
      int pos = idx;
      while (pos < n) {
         if (S[pos] == 1) {
            pos = *NJ.upper_bound(pos);
         } else {
            S[pos] = S[pos] - 1;
            if (S[pos] == 1)
               NJ.erase(pos);
            pos = pos + S[pos] + 1;
         }
      }
   }
   cout << res << endl;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      solve();
   }
}