//#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <iostream>
#include <math.h>
#include <vector>
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

typedef int ll;
const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;
typedef vector<int> vi;

struct MCMF {
   int N;
   vector<vi> ed, red;
   vector<VL> cap, flow, cost;
   vi seen;
   VL dist, pi;
   vector<pii> par;

   MCMF(int N) : N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap), seen(N), dist(N), pi(N), par(N) {}

   void addEdge(int from, int to, ll cap, ll cost) {
      debug(from, to, cap, cost);
      this->cap[from][to] = cap;
      this->cost[from][to] = cost;
      ed[from].push_back(to);
      red[to].push_back(from);
   }

   void path(int s) {
      fill(all(seen), 0);
      fill(all(dist), INF);
      dist[s] = 0;
      ll di;

      __gnu_pbds::priority_queue<pair<ll, int>> q;
      vector<decltype(q)::point_iterator> its(N);
      q.push({0, s});

      auto relax = [&](int i, ll cap, ll cost, int dir) {
         ll val = di - pi[i] + cost;
         if (cap && val < dist[i]) {
            dist[i] = val;
            par[i] = {s, dir};
            if (its[i] == q.end())
               its[i] = q.push({-dist[i], i});
            else
               q.modify(its[i], {-dist[i], i});
         }
      };

      while (!q.empty()) {
         s = q.top().second;
         q.pop();
         seen[s] = 1;
         di = dist[s] + pi[s];
         trav(i, ed[s]) if (!seen[i]) relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
         trav(i, red[s]) if (!seen[i]) relax(i, flow[i][s], -cost[i][s], 0);
      }
      rep(i, N) pi[i] = min(pi[i] + dist[i], INF);
   }

   pair<ll, ll> maxflow(int s, int t) {
      ll totflow = 0, totcost = 0;
      while (path(s), seen[t]) {
         ll fl = INF;
         for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
            fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
         totflow += fl;
         for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
            if (r)
               flow[p][x] += fl;
            else
               flow[x][p] -= fl;
      }
      rep(i, N) rep(j, N) totcost += cost[i][j] * flow[i][j];
      return {totflow, totcost};
   }
};

int32_t main() {
   _upgrade;
   const int D = 5000;
   int n, p, s;
   n = 3000;
   p = n / 2;
   s = n / 2;
   cin >> n >> p >> s;

   MCMF F(n + 6);

   int so = n;
   int trg = n + 1;
   int sport = n + 3;
   int prog = n + 2;

   F.addEdge(sport, trg, s, 0);
   F.addEdge(prog, trg, p, 0);

   debug("WTF");

   rep(i, n) { F.addEdge(so, i, 1, 0); }

   rep(i, n) {
      int a;
      a = rand() % D;
      cin >> a;
      F.addEdge(i, prog, 1, D - a);
   }

   rep(i, n) {
      int a;
      a = rand() % D;

      cin >> a;
      F.addEdge(i, sport, 1, D - a);
   }

   auto [a, b] = F.maxflow(so, trg);
   debug(a, b);
   b = D * a - b;
   debug(a, b);

   cout << b << endl;
   rep(i, n) if (F.flow[i][prog]) cout << i + 1 << " ";
   cout << endl;
   rep(i, n) if (F.flow[i][sport]) cout << i + 1 << " ";
   cout << endl;
}