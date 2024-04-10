#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
#pragma GCC optimize("-O3")
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
#define what(x) cerr << #x << " is " << x << endl;

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

int n, m;

void wyrzuc(int i, pii P, map<int, set<int>> &M, priority_queue<pii> &Q) {
   M[P.st].erase(i);
   M[P.nd].erase(i);
   Q.push({-sz(M[P.st]), P.st});
   Q.push({-sz(M[P.nd]), P.nd});
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      cin >> n >> m;
      int cnt = 0;

      map<int, set<int>> M;
      vector<pii> X(n);
      priority_queue<pii> Q;

      rep(i, m) {
         int a, b;
         cin >> a >> b;
         if (a != b) {
            M[a].insert(i);
            M[b].insert(i);
         }
         X[i] = {a, b};
      }

      for (auto &m : M) {
         Q.push({-sz(m.nd), m.st});
      }
      // debug(M);
      while (!Q.empty()) {
         auto q = Q.top();
         Q.pop();
         if (-q.st != sz(M[q.nd]))
            continue;
         if (q.st == 0) {
            M.erase(q.nd);
            continue;
         }
         if (q.st == -1) {
            cnt++;
            int x = *M[q.nd].begin();
            wyrzuc(x, X[x], M, Q);
         }
         if (q.st == -2) {
            cnt += 2;
            int x = *M[q.nd].begin();
            wyrzuc(x, X[x], M, Q);
         }
         // debug(M);
      }
      cout << cnt << endl;
   }
}