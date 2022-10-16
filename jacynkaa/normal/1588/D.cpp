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

const int MAXN = 11;
const int MAXC = 256;

vector<int> tab[MAXN][MAXC];
vector<char> C;
int n;

void pre() {
   rep(i, MAXN) rep(j, MAXC) tab[i][j].clear();
   C.clear();
   rep(i, 26) {
      C.push_back('a' + i);
      C.push_back('A' + i);
   }
}

vector<vector<int>> get(char c, int k) {
   vector<vector<int>> res;

   if (k == 0) {
      for (int t : tab[k][c])
         res.push_back({t});
      return res;
   }

   auto T = get(c, k - 1);
   for (int t : tab[k][c])
      for (auto v : T) {
         v.push_back(t);
         res.push_back(v);
      }
   return res;
}

vector<vector<int>> get(char c) { return get(c, n - 1); }

pair<ull, bool> get(char c, vector<int> &v) {
   ull T = 0;
   rep(i, n) {
      bool done = false;
      for (int t : tab[i][c]) {
         if (t < v[i]) {
            T <<= 1;
            if (t == tab[i][c].back())
               T ^= 1;
            done = true;
            break;
         }
      }
      if (!done)
         return {0, false};
   }

   return {T, true};
}

ull get(vector<int> &v, char c) {
   ull T = 0;
   rep(i, sz(v)) {
      T <<= 1;
      if (v[i] == tab[i][c].back())
         T ^= 1;
   }
   return T;
}

string ssolve() {
   cin >> n;
   vector<string> S(n);
   rep(i, n) {
      string T(all(C));
      T.insert(T.end(), all(C));
      random_shuffle(all(T));
      S[i] = T;
      cin >> S[i];
   }
   debug(S);

   rep(i, n) for (int j = sz(S[i]) - 1; j >= 0; j--) tab[i][S[i][j]].push_back(j);

   vector<vector<int>> V;

   for (char c : C) {
      auto T = get(c);
      //   debug(c, T);
      V.insert(V.end(), all(T));
   }
   sort(all(V));

   if (sz(V) == 0)
      return "";

   debug(V);

   vector<map<ull, int>> U(256);
   rep(i, sz(V)) {
      char c = S[0][V[i][0]];
      U[c][get(V[i], c)] = i;
   }

   vector<pii> dp(sz(V));

   rep(i, sz(V)) {
      auto v = V[i];
      dp[i] = {1, -1};
      for (char c : C) {
         auto [h, ok] = get(c, v);
         if (ok) {
            int l = U[c][h];
            dp[i] = max(dp[i], {dp[l].st + 1, l});
         }
      }
   }

   auto t = max_element(all(dp)) - dp.begin();

   string res;

   while (t != -1) {
      res.push_back(S[0][V[t][0]]);
      t = dp[t].nd;
   }

   reverse(all(res));
   return res;
}

void solve() {
   auto res = ssolve();

   cout << sz(res) << endl;
   cout << res << endl;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      pre();
      solve();
   }
}