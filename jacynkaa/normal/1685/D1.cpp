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

typedef vector<int> vd;
typedef vd vi;
bool zero(int x) { return x == 0; }

int MinCostMatching(const vector<vd> &cost, vi &L, vi &R) {
   int n = sz(cost), mated = 0;
   vd dist(n), u(n), v(n);
   vi dad(n), seen(n);

   /// construct dual feasible solution
   rep(i, n) {
      u[i] = cost[i][0];
      fwd(j, 1, n) u[i] = min(u[i], cost[i][j]);
   }
   fwd(j, 0, n) {
      v[j] = cost[0][j] - u[0];
      fwd(i, 1, n) v[j] = min(v[j], cost[i][j] - u[i]);
   }

   /// find primal solution satisfying complementary slackness
   L = R = vi(n, -1);
   fwd(i, 0, n) fwd(j, 0, n) {
      if (R[j] != -1)
         continue;
      if (zero(cost[i][j] - u[i] - v[j])) {
         L[i] = j;
         R[j] = i;
         mated++;
         break;
      }
   }

   for (; mated < n; mated++) { // until solution is feasible
      int s = 0;
      while (L[s] != -1)
         s++;
      fill(all(dad), -1);
      fill(all(seen), 0);
      fwd(k, 0, n) dist[k] = cost[s][k] - u[s] - v[k];

      int j = 0;
      for (;;) { /// find closest
         j = -1;
         fwd(k, 0, n) {
            if (seen[k])
               continue;
            if (j == -1 || dist[k] < dist[j])
               j = k;
         }
         seen[j] = 1;
         int i = R[j];
         if (i == -1)
            break;
         fwd(k, 0, n) { /// relax neighbors
            if (seen[k])
               continue;
            auto new_dist = dist[j] + cost[i][k] - u[i] - v[k];
            if (dist[k] > new_dist) {
               dist[k] = new_dist;
               dad[k] = j;
            }
         }
      }

      /// update dual variables
      fwd(k, 0, n) {
         if (k == j || !seen[k])
            continue;
         auto w = dist[k] - dist[j];
         v[k] += w, u[R[k]] -= w;
      }
      u[s] += dist[j];

      /// augment along path
      while (dad[j] >= 0) {
         int d = dad[j];
         R[j] = R[d];
         L[R[j]] = j;
         j = d;
      }
      R[j] = s;
      L[s] = j;
   }
   auto value = vd(1)[0];
   fwd(i, 0, n) value += cost[i][L[i]];
   return value;
}

const int inf = 1e6;

int get(vector<int> p, vector<int> q) {
   debug(q);
   int res = 0;
   rep(i, sz(p)) res += abs(p[i] - q[p[(i + 1) % sz(p)]]);
   debug(res);
   return res;
}
void solve() {
   int n;
   cin >> n;
   //  n = rand() % 100;

   vector<int> p(n);
   rep(i, n) cin >> p[i];

   // iota(all(p), 1);
   // random_shuffle(all(p));

   rep(i, n) p[i]--;
   vector<int> I(n);
   rep(i, n) I[p[i]] = i;

   debug(p);

   vector<bool> vis(n, false);

   vector<vector<int>> P;
   rep(i, n) if (!vis[i]) {
      vector<int> V;
      V.push_back(i);
      while (I[V.back()] != V[0])
         V.push_back(I[V.back()]);
      for (int v : V)
         vis[v] = true;
      V.push_back(V[0]);
      V.erase(V.begin());
      P.push_back(V);
   }

   debug(P);
   vector<int> res = P[0];
   for (auto &p : P) {
      debug(p, p.back());
      rep(i, sz(res)) {
         // debug(i, res[i]);
         if (res[i] == p.back() - 1) {
            res.insert(res.begin() + i + 1, all(p));
            debug("wtf");
            break;
         }
      }
   }
   debug(p, res);

   int wynik = get(res, p);
   debug(sz(P));

   assert(wynik == 2 * (sz(P) - 1));

   debug(P);
   for (int x : res)
      cout << x + 1 << " ";
   cout << endl;

   // rep(i, n) rep(j, n) { C[i][j] = i == j ? inf : abs(i - p[j]); }

   // int res = MinCostMatching(C, L, R);
   // debug(res);
   // vector<int> Q = {0};
   // while (sz(Q) != n)
   //    Q.push_back(L[Q.back()]);
   // for (int q : Q)
   //    cout << q + 1 << " ";
   // cout << endl;
}
int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}