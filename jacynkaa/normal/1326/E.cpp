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

#define r1 ((l + r) / 2)   // ulatwia branie srodka przedzialu
#define l2 (r1 + 1)        // same
const int inf = 1LL << 30; // ustawic w zaleznosci

struct SegmentTree { // drzewo przedzia-przedzia (add,sum)

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

struct LazySegmentTree { // drzewo przedzia-przedzia (add,min)

   struct content {
      int mod, maks; // modyfikator w wezle i maks biorac pod uwage tylko modyfikatory tylko pod wezlem
   };

   vector<content> C;
   int size;

   LazySegmentTree(int x) { size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2); } // drzewo przedzialowe dla zakresu [0,x),

   inline void push(int wezel) {
      C[2 * wezel].mod += C[wezel].mod;
      C[2 * wezel + 1].mod += C[wezel].mod;
      C[2 * wezel].maks += C[wezel].mod;
      C[2 * wezel + 1].maks += C[wezel].mod;
      C[wezel].mod = 0;
   }
   inline void update(int wezel) { C[wezel].maks = min(C[2 * wezel + 1].maks, C[2 * wezel].maks) + C[wezel].mod; }

   void add(int p, int q, int val, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
      if (p > q)
         return;

      if (p == l && q == r) {
         C[wezel].mod += val;
         C[wezel].maks += val;
         return;
      }
      push(wezel);

      add(p, min(r1, q), val, l, r1, 2 * wezel);
      add(max(l2, p), q, val, l2, r, 2 * wezel + 1);

      update(wezel);
   }

   int query(int p, int q, int l, int r, int wezel = 1) { // max[p,q]
      if (p > q)
         return inf; // UWAGA

      if (p == l && q == r)
         return C[wezel].maks;

      return min(query(p, min(r1, q), l, r1, 2 * wezel), query(max(l2, p), q, l2, r, 2 * wezel + 1)) + C[wezel].mod;
   }

   void add(int p, int q, int val) { add(p, q, val, 0, size - 1); }
   int query(int p, int q) { return query(p, q, 0, size - 1); }
};

int32_t main() {
   _upgrade;
   int n;
   cin >> n;
   vector<int> P(n);
   vector<int> Q(n);
   vector<int> pos(n + 1);
   rep(i, n) cin >> P[i], pos[P[i]] = i + 1;
   rep(i, n) cin >> Q[i];

   LazySegmentTree L(n + 2);

   int res = n;
   for (int q : Q) {

      while (L.query(0, pos[res]) > 0) {
         L.add(0, pos[res], -1);
         res--;
      }
      L.add(0, q, 1);
      cout << res << " ";
   }
}