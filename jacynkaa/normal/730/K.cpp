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

const int MAXN = 1e6;
int n, m, s, t;

set<int> G[MAXN];
int indeg[MAXN];
set<int> S[MAXN];
bool vis[MAXN];
int cur[MAXN];
vector<int> T;
vector<pii> U;
set<int> Q;
vector<int> V;

void skieruj(int a, int b) {
   debug(a, b);
   if (S[a].insert(b).nd) {
      indeg[b]++;
      Q.erase(b);
      G[a].erase(b);
      G[b].erase(a);
   }
}

void skieruj() {
   rep(i, sz(T) - 1) skieruj(T[i], T[i + 1]);
   for (int a : T)
      vis[a] = true;

   debug(T);

   T.clear();
}

bool dfs(int x, int idx) {
   T.push_back(x);
   debug("dfs", x);

   if (vis[x])
      return true;
   cur[x] = idx;

   for (int y : G[x])
      if (cur[y] != idx)
         if (dfs(y, idx))
            return true;

   T.pop_back();
   vis[x] = false;
   return false;
}

void clear() { rep(i, n) cur[i] = vis[i] = 0, G[i].clear(), S[i].clear(), T.clear(), U.clear(), Q.clear(), V.clear(), indeg[i] = 0; }

void er(int x) {
   for (int s : S[x]) {
      debug(s, indeg[s]);
      indeg[s]--;
      if (indeg[s] == 0)
         Q.insert(s);
   }
}

void solve() {
   cin >> n >> m >> s >> t;
   s--, t--;
   clear();

   rep(i, m) {
      int a, b;
      cin >> a >> b;
      G[--a].insert(--b);
      G[b].insert(a);
   }

   vis[t] = true;

   Q = {s};

   int idx = 1;
   while (!Q.empty()) {
      int x = *Q.begin();
      debug(x, Q);
      Q.erase(x);

      while (sz(G[x])) {
         T = {x};
         cur[x] = idx;
         int z = *G[x].begin();
         if (dfs(z, idx++) == false) {
            cout << "No\n";
            return;
         }
         skieruj();
      }
      er(x);
   }

   int c = 0;
   rep(i, n) c += sz(S[i]);

   if (c == m) {
      cout << "Yes\n";
      rep(i, n) for (int a : S[i]) cout << i + 1 << " " << a + 1 << endl;
   } else {
      cout << "No\n";
   }
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}