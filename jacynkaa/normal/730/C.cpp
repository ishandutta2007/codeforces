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

struct FT {
   const int M = 13;
   vector<ll> s;
   FT(int n) : s(n) {}
   void update(int pos, ll dif) { // a[pos] += dif
      for (; pos < sz(s); pos |= pos + 1)
         s[pos] += dif;
   }
   ll query(int pos) { // sum of values in [0, pos)
      ll res = 0;
      for (; pos > 0; pos &= pos - 1)
         res += s[pos - 1];
      return res;
   }
   int lower_bound(ll sum) { // min pos st sum of [0, pos] >= sum
      // Returns n if no sum is >= sum, or -1 if empty sum is.
      if (sum <= 0)
         return -1;
      int pos = 0;
      for (int pw = 1 << M; pw; pw >>= 1) {
         if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
            pos += pw, sum -= s[pos - 1];
      }
      return pos;
   }
};

const int MAXN = 5002;
vector<int> P;
vector<int> G[MAXN];
vector<pii> S[MAXN];
int n, m;

bool check(int r, int a, FT &cnt, FT &sum) {
   int idx = cnt.lower_bound(r);
   if (idx == cnt.s.size())
      return false;

   auto cn = cnt.query(idx);
   int cost = sum.query(idx);
   cost += (r - cn) * P[idx];
   return cost <= a;
}

void add(pii PP, FT &cnt, FT &sum) {
   debug(PP);
   auto [k, p] = PP;
   int i = lower_bound(all(P), p) - P.begin();
   cnt.update(i, k);
   sum.update(i, k * p);
}

int query() {
   int g, r, a;
   cin >> g >> r >> a;
   --g;

   FT cnt(MAXN);
   FT sum(MAXN);

   vector<int> dist(n, -1);
   dist[g] = 0;
   queue<int> Q;
   Q.push(g);

   while (!Q.empty()) {
      int q = Q.front();
      Q.pop();

      for (auto p : S[q])
         add(p, cnt, sum);

      if (check(r, a, cnt, sum))
         return dist[q];

      for (int p : G[q])
         if (dist[p] == -1) {
            dist[p] = dist[q] + 1;
            Q.push(p);
         }
   }
   return -1;
}

int32_t main() {
   _upgrade;

   cin >> n >> m;
   rep(i, m) {
      int a, b;
      cin >> a >> b;
      G[--a].push_back(--b);
      G[b].push_back(a);
   }

   int w;
   cin >> w;

   rep(i, w) {
      int c, k, p;
      cin >> c >> k >> p;
      P.push_back(p);
      S[--c].push_back({k, p});
   }

   sort(all(P));
   P.erase(unique(all(P)), P.end());

   debug(P);

   int q;
   cin >> q;
   rep(i, q) {
      int res = query();
      cout << res << endl;
   }
}