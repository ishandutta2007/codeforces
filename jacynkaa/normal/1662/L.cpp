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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
// mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
#ifdef LOCAL
ostream &operator<<(ostream &out, string str) {
   for (char c : str)
      out << c;
   return out;
}
template <class L, class R> ostream &operator<<(ostream &out, pair<L, R> p) { return out << "(" << p.st << ", " << p.nd << ")"; }
template <class L, class R, class S> ostream &operator<<(ostream &out, tuple<L, R, S> p) {
   auto &[a, b, c] = p;
   return out << "(" << a << ", " << b << ", " << c << ")";
}
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
#define debug(...) 42
#endif

#define int long long

// #define r1 ((l + r) / 2) // ulatwia branie srodka przedzialu
// #define l2 (r1 + 1)

// struct SegmentTree { // drzewo przedzial-przedzial (add,sum)

//    vector<deque<pii>> C;
//    int size;

//    SegmentTree(int x) { size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2); } // drzewo przedzialowe dla zakresu [0,x),

//    void add(int p, int q, int val, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
//       if (p > q)
//          return;

//       if (p == l && q == r) {
//          C[wezel].mod += val;
//          C[wezel].sum += (q - p + 1) * val;
//          return;
//       }

//       add(p, min(r1, q), val, l, r1, 2 * wezel);
//       add(max(l2, p), q, val, l2, r, 2 * wezel + 1);

//       C[wezel].sum = C[2 * wezel].sum + C[2 * wezel + 1].sum + C[wezel].mod * (r - l + 1);
//    }

//    int query(int p, int q, int l, int r, int val, int wezel = 1) { // suma na przedzial [p,q]
//       if (p > q)
//          return 0;

//       if (p == l && q == r) {
//          auto itr = lower_bound(all(C[wezel]))
//       }

//       return query(p, min(r1, q), l, r1, 2 * wezel) + query(max(l2, p), q, l2, r, 2 * wezel + 1) + C[wezel].mod * (q - p + 1);
//    }

//    void add(int p, int q, int val) { add(p, q, val, 0, size - 1); }
//    int query(int p, int q) { return query(p, q, 0, size - 1); }
// };

const int MAXN = 2e5 + 99;
const int inf = 1e9;
set<pii> S[MAXN];
int n, v;

bool ok(pii a, pii b) {
   auto [x1, t1] = a;
   auto [x2, t2] = b;
   return abs(x1 - x2) <= abs(t1 - t2) * v;
}

bool check(set<pii> &S, pii p) {
   debug(S, p);
   auto itr = S.upper_bound(p);
   if (itr != S.end() && ok(p, *itr))
      return true;
   if (itr != S.begin() && ok(p, *(--itr)))
      return true;
   return false;
}

int32_t main() {
   _upgrade;
   S[0] = {{0, 0}};
   cin >> n >> v;
   vector<pii> V(n);
   vector<int> U(n);
   iota(all(U), 0);

   rep(i, n) cin >> V[i].nd;
   rep(i, n) cin >> V[i].st;
   debug(V);

   for (auto v : V) {
      int p = 0;
      int q = MAXN - 1;
      while (p != q) {
         int s = (p + q) / 2;
         if (check(S[s], v))
            p = s + 1;
         else
            q = s;
      }
      if (p)
         S[p].insert(v);
   }

   rep(i, MAXN) if (sz(S[i]) == 0) {
      cout << i - 1 << endl;
      exit(0);
   }
}