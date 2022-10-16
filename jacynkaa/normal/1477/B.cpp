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

#define r1 ((l + r) / 2)   // ulatwia branie srodka przedzialu
#define l2 (r1 + 1)        // same
const int inf = 1LL << 30; // ustawic w zaleznosci

struct LazySegmentTree { // drzewo przedzia-przedzia (add,min)

   struct content {
      int mod, sum; // modyfikator w wezle i mini biorac pod uwage tylko modyfikatory tylko pod wezlem
   };

   vector<content> C;
   int size;

   LazySegmentTree(int x) { size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2, {-1, 0}); } // drzewo przedzialowe dla zakresu [0,x),

   inline void push(int wezel) {
      C[2 * wezel].mod = C[wezel].mod;
      C[2 * wezel + 1].mod = C[wezel].mod;
      C[wezel].mod = -1;
   }
   inline void update(int wezel) { C[wezel].sum = C[2 * wezel + 1].sum + C[2 * wezel].sum; }

   void add(int p, int q, int mod, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
      if (p > q)
         return;

      if (p == l && q == r) {
         C[wezel].mod = mod;
         C[wezel].sum = mod * (r - l + 1);
         return;
      }
      if (C[wezel].mod != -1) {
         push(wezel);
         C[2 * wezel].sum = C[2 * wezel].mod * (r - l + 1) / 2;
         C[2 * wezel + 1].sum = C[2 * wezel + 1].mod * (r - l + 1) / 2;
      }

      add(p, min(r1, q), mod, l, r1, 2 * wezel);
      add(max(l2, p), q, mod, l2, r, 2 * wezel + 1);

      update(wezel);
   }

   int query(int p, int q, int l, int r, int wezel = 1) { // max[p,q]
      if (p > q)
         return 0; // UWAGA
      if (C[wezel].mod != -1)
         return (q - p + 1) * C[wezel].mod;

      if (p == l && q == r) {
         return C[wezel].sum;
      }

      return query(p, min(r1, q), l, r1, 2 * wezel) + query(max(l2, p), q, l2, r, 2 * wezel + 1);
   }

   void add(int p, int q, int val) { add(p, q, val, 0, size - 1); }
   int query(int p, int q) { return query(p, q, 0, size - 1); }
};

int n, q;

bool solve() {
   string S;
   string F;
   cin >> S >> F;
   debug(S, F);
   LazySegmentTree L(2 * n);
   rep(i, n) L.add(i, i, F[i] == '1');
   vector<pii> Q;
   rep(i, q) {
      int l, r;
      cin >> l >> r;
      Q.push_back({l, r});
   }
   reverse(all(Q));
   debug(q);

   for (auto q : Q) {
      q.st--, q.nd--;
      int rozmiar = (q.nd - q.st + 1);
      auto sum = L.query(q.st, q.nd);
      debug(q, rozmiar, sum);

      if (sum <= ((rozmiar - 1) / 2)) {
         debug("setting 0");
         L.add(q.st, q.nd, 0);
      } else if ((rozmiar - sum) <= ((rozmiar - 1) / 2)) {
         L.add(q.st, q.nd, 1);
         debug("setting 1");
      } else
         return false;

      // rep(i, n) cerr << (L.query(i, i) == 1 ? '1' : '0');
      // cerr << endl;
   }
   rep(i, n) if (bool(L.query(i, i)) != (S[i] == '1')) return false;
   return true;
}

int32_t main() {
   _upgrade;
   int Z;

   cin >> Z;
   while (Z--) {
      cin >> n >> q;
      cout << (solve() ? "YES" : "NO") << endl;
   }
}