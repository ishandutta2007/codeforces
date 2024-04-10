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

typedef vector<int> vi;

bool find(int j, vector<vi> &g, vi &btoa, vi &vis) {
   if (btoa[j] == -1)
      return 1;
   vis[j] = 1;
   int di = btoa[j];
   trav(e, g[di]) if (!vis[e] && find(e, g, btoa, vis)) {
      btoa[e] = di;
      return 1;
   }
   return 0;
}

int dfsMatching(vector<vi> &g, vi &btoa) {
   vi vis;
   rep(i, sz(g)) {
      vis.assign(sz(btoa), 0);
      trav(j, g[i]) if (find(j, g, btoa, vis)) {
         btoa[j] = i;
         break;
      }
   }
   return sz(btoa) - (int)count(all(btoa), -1);
}

int get(string Q) {
   int a = 0;
   reverse(all(Q));
   for (auto q : Q) {
      a <<= 1;
      if (q == '1')
         a++;
   }
   return a;
}

int32_t main() {
   _upgrade;
   int d, n;
   cin >> d >> n;
   vector<int> X;
   vector<int> btoa(n, -1);
   vector<vi> G(n);
   rep(i, n) {
      string Q;
      cin >> Q;
      X.push_back(get(Q));
   }

   sort(all(X), [&](auto &a, auto &b) { return __builtin_popcount(a) > __builtin_popcount(b); });
   debug(X);

   rep(i, n) for (int j = i + 1; j < n; j++) if ((X[i] & X[j]) == X[j]) G[j].push_back(i);
   // rep(i, n) sort(all(G[i]));

   dfsMatching(G, btoa);

   debug(btoa);

   vector<int> Q;
   vector<char> res;

   rep(i, n) if (count(all(btoa), i) == 0) Q.push_back(i);

   debug(Q);

   for (auto q : Q) {
      vector<int> R;
      while (q != -1) {
         R.push_back(X[q]);
         q = btoa[q];
      }
      R.push_back(0);
      reverse(all(R));
      debug(R);
      rep(i, sz(R) - 1) {
         auto a = R[i + 1] ^ R[i];
         for (int k = 0; k < d; k++)
            if (a & (1 << k))
               res.push_back('0' + k);
      }
      res.push_back('R');
   }
   res.pop_back();

   debug(res);

   cout << sz(res) << endl;
   for (auto c : res)
      cout << c << " ";
   cout << endl;
}