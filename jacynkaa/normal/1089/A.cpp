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

const int MAXN = 202;

vector<pii> getA(int t) {
   vector<pii> res;
   rep(i, t - 1) {
      res.push_back({i, t});
      res.push_back({t, i});
   }
   for (int i = t + 1; i < MAXN; i++) {
      res.push_back({i, i - 2});
      res.push_back({i - 2, i});
   }
   return res;
}

typedef pair<pii, vector<pii>> Match;

vector<pii> S[2] = {getA(25), getA(15)};

int add(int a, pii b) {
   if (b.st < b.nd)
      return a + 1;
   else
      return a + 4;
}

bool legal(int a) {
   int x = a % 4;
   int y = a / 4;
   return x < 3 && y < 3;
}
pii get(int a) { return {a % 4, a / 4}; }

const int W = 16;
vector<pii> dp[MAXN][MAXN][W];

// int get_sum();

int get_type(int a) { return a == 10; }

void pre() {
   // dp[0][0] = {{{0, 0}, {}}};
   for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++)
         if (i + j != 0) {
            //  debug(i, j);
            rep(l, 2) {
               for (auto [a, b] : S[l])
                  if (a <= i && b <= j) {
                     rep(w, W) {
                        auto &res = dp[i - a][j - b][w];
                        if (legal(w) && get_type(w) == l && (sz(res) || (i == a && b == j && w == 0))) {
                           auto p = w;
                           p = add(p, {a, b});
                           if (sz(dp[i][j][p]) == 0) {
                              auto t = res;
                              t.push_back({a, b});
                              dp[i][j][p] = t;
                           }
                           // V.push_back({p, t});
                        }
                     }
                     // map<pii, vector<pii>> M;
                     // for (auto [w, res] : V)
                     //    M[w] = res;
                     // for (auto [w, res] : M)
                     //    dp[i][j].push_back({w, res});
                  }
            }
         }
   // rep(w, W) debug(w, dp[80][100][w]);
}

void pr(pii a) { cout << a.st << ":" << a.nd << " "; }

int32_t main() {
   _upgrade;
   pre();
   debug("DONE");
   int m;
   cin >> m;
   while (m--) {
      int a, b;
      cin >> a >> b;
      bool ok = false;
      typedef pair<pii, vector<pii>> Match;

      map<int, Match> M;
      rep(w, W) {
         auto [x, y] = get(w);
         if ((x == 3 || y == 3) && sz(dp[b][a][w]) == x + y) {
            M[y - x] = {{x, y}, dp[b][a][w]};
         }
      }
      debug(M);
      if (sz(M)) {
         auto [p, res] = M[M.begin()->st];
         pr(p);

         cout << endl;
         for (auto [q, w] : res)
            pr({w, q});
         cout << endl;
         ok = true;

      } else {
         cout << "Impossible\n";
      }
   }
}