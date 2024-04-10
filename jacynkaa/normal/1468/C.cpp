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
#define int long long

bool visited[(int)1e6 + 99];
int32_t main() {
   _upgrade;
   queue<pii> Q;
   priority_queue<pii> QP;
   int q;
   cin >> q;
   int x = 0;

   rep(i, q) {
      int a;
      cin >> a;
      if (a == 1) {
         int b;
         cin >> b;
         Q.push({b, -x});
         QP.push({b, -x});
         x++;

         continue;
      }
      if (a == 2) {
         while (visited[abs(Q.front().nd)])
            Q.pop();
         int a = abs(Q.front().nd);
         Q.pop();
         visited[a] = true;
         cout << a + 1 << " ";

      } else {
         while (visited[abs(QP.top().nd)])
            QP.pop();
         int a = abs(QP.top().nd);
         QP.pop();
         visited[a] = true;
         cout << a + 1 << " ";
      }
   }
   cout << endl;
}