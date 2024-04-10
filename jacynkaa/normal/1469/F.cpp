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
#define debug(...)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     \
   if (false)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \
   cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)

#define int long long

#define r1 ((l + r) / 2) // ulatwia branie srodka przedzialu
#define l2 (r1 + 1)      // same

struct SegmentTree { // drzewo przedzia-przedzia (add,sum) nie ma pewnosci ze dziala

   struct content {
      int mod, sum;
   };

   vector<content> C;
   int size;

   SegmentTree(int x) { size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2); } // drzewo przedzialowe dla zakresu [0,x),

   void add(int p, int q, int val, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
      if (p > q)
         return;

      if (p == l && q == r) {
         C[wezel].mod += val;
         C[wezel].sum += (q - p + 1) * val;
         return;
      }

      add(p, min(r1, q), val, l, r1, 2 * wezel);
      add(max(l2, p), q, val, l2, r, 2 * wezel + 1);

      C[wezel].sum = C[2 * wezel].sum + C[2 * wezel + 1].sum + C[wezel].mod * (r - l + 1);
   }

   int query(int p, int q, int l, int r, int wezel = 1) { // suma na przedzial [p,q]
      if (p > q)
         return 0;

      if (p == l && q == r)
         return C[wezel].sum;

      return query(p, min(r1, q), l, r1, 2 * wezel) + query(max(l2, p), q, l2, r, 2 * wezel + 1) + C[wezel].mod * (q - p + 1);
   }

   void add(int p, int q, int val) { add(p, q, val, 0, size - 1); }
   int query(int p, int q) { return query(p, q, 0, size - 1); }
};

const int MAXL = 1e6 + 99;
SegmentTree D(MAXL);
int n, k;

int get_ans() {

   rep(i, MAXL) {
      if (D.query(0, i) >= k) {
         debug(i, D.query(0, i));
         return i;
      }
   }
   return -1;
}

int32_t main() {
   _upgrade;

   cin >> n >> k;
   vector<int> L(n);
   rep(i, n) cin >> L[i];
   sort(all(L));
   D.add(0, 0, 1);
   int mini = 0;

   while (!L.empty() && D.query(mini, mini + 1) < k) {

      if (D.query(mini, mini) == 0) {
         mini++;
         continue;
      }
      D.add(mini, mini, -1);
      auto l = L.back();
      debug(mini, l);
      L.pop_back();
      int t1 = (l - 1) / 2;
      auto t2 = l / 2;
      debug(t1, t2);
      D.add(mini + 2, mini + 1 + t1, 1);
      D.add(mini + 2, mini + 1 + t2, 1);

      debug(D.query(0, MAXL - 1));
   }
   debug(D.query(mini, mini + 1));
   cout << get_ans() << endl;
}