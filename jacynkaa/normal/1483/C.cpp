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

vector<pair<int, pair<int, bool>>> get(int idx, map<int, int> &M) {
   vector<pair<int, pair<int, bool>>> res;
   auto itr1 = M.lower_bound(idx);
   if (itr1 != M.begin()) {
      itr1--;
      res.push_back({itr1->nd, {itr1->st, itr1 != M.begin()}});
   }
   auto itr2 = M.upper_bound(idx);

   if (itr2 != M.end()) {
      res.push_back({itr2->nd, {itr2->st, (itr2) != (--M.end())}});
   }

   return res;
}

int32_t main() {
   _upgrade;
   int n;
   cin >> n;

   vector<vector<int>> X(n);

   rep(i, n) { X[i] = vector<int>(3, i); }
   rep(i, n) cin >> X[i][0];
   rep(i, n) cin >> X[i][1];

   sort(all(X), greater<vector<int>>());

   debug(X);

   map<int, int> M;
   rep(i, n) M[i] = 0;

   for (auto x : X) {
      int b = x[1];
      int idx = x[2];
      auto T = get(idx, M);
      sort(all(T));
      debug(T);

      M.erase(idx);
      debug(M);
      if (b <= 0) {
         bool f = false;

         for (auto t : T) {
            if (t.st == 0) {
               f = true;
               break;
            }
            if (t.st <= -b && t.nd.nd) {
               M.erase(t.nd.st);
               f = true;
               break;
            }
         }
         if (f)
            continue;
      }

      for (auto t : T) {
         if (t.st > 0) {
            b += t.st;
            M.erase(t.nd.st);
         }
      }
      M[idx] = b;
   }
   debug(M);
   assert(sz(M) == 1);
   cout << M.begin()->nd << endl;
}