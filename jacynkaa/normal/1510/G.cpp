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

const int MAXN = 110;
int parent[MAXN];
vector<int> G[MAXN];
int dist[MAXN];
bool visited[MAXN];
vector<int> res;

void er(vector<int> &X, int a) {
   for (auto itr = X.begin(); itr != X.end(); itr++)
      if (*itr == a) {
         X.erase(itr);
         break;
      }
}

void clear() {
   rep(i, MAXN) {
      parent[i] = -1;
      G[i].clear();
      dist[i] = 0;
      visited[i] = false;
   }
   res.clear();
}

void dfs1(int x) {
   for (auto y : G[x]) {
      dist[y] = dist[x] + 1;
      dfs1(y);
   }
}

void dfs2(int x) {
   res.push_back(x);
   for (auto y : G[x]) {
      dfs2(y);
      res.push_back(x);
   }
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      clear();
      int k, n;
      cin >> n >> k;
      rep(i, n - 1) {
         int a;
         cin >> a;
         G[--a].push_back(i + 1);
         parent[i + 1] = a;
      }

      dist[0] = 1;
      dfs1(0);

      pii best = {-1, -1};
      rep(i, n) if (dist[i] <= k) best = max(best, make_pair(dist[i], i));

      debug(best);

      int l = best.nd;

      vector<int> Q;
      rep(i, n) if (sz(G[i]) == 0 && i != l) Q.push_back(i);

      while (n > k) {
         int a = Q.back();
         Q.pop_back();
         n--;

         int p = parent[a];

         er(G[p], a);
         if (sz(G[p]) == 0 && p != l)
            Q.push_back(p);
      }

      int r = l;
      while (parent[r] != -1) {
         int p = parent[r];
         er(G[p], r);
         G[p].push_back(r);
         r = p;
      }

      dfs2(0);

      debug(res);
      while (res.back() != l)
         res.pop_back();

      cout << sz(res) - 1 << endl;
      for (int a : res)
         cout << a + 1 << " ";
      cout << endl;
   }
}