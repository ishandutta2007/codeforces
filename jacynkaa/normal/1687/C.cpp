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

int n, m;

map<pii, int> M;
set<int> S;
vector<vector<pii>> P, K;
deque<pii> Q;

void clear() {
   M.clear();
   S.clear();
   Q.clear();

   rep(i, n) S.insert(i);
   P = vector<vector<pii>>(n);
   K = P;
}

void add(int p, vector<vector<pii>> &P) {
   for (auto q : P[p]) {
      M[q]++;
      if (M[q] == 2)
         Q.push_back(q);
   }
   P[p].clear();
}

void solve() {
   cin >> n >> m;

   clear();

   vector<int> A(n), B(n);
   rep(i, n) cin >> A[i];
   rep(i, n) cin >> B[i];

   set<pii> PP;
   rep(j, m) {
      int a, b;
      cin >> a >> b;
      PP.insert({--a, --b});
   }

   for (auto [a, b] : PP) {
      P[a].push_back({a, b});
      K[b].push_back({a, b});
   }

   int cnt = 0;
   rep(i, n) {
      int o = 0;
      o += (cnt == 0);
      if (cnt == 0)
         add(i, P);
      cnt += A[i] - B[i];
      if (cnt == 0)
         add(i, K);
      o += (cnt == 0);

      if (o == 2)
         Q.push_back({i, i});
   }

   debug(Q);

   while (!Q.empty()) {
      auto [a, b] = Q.front();
      debug(a, b);
      Q.pop_front();
      while (true) {
         auto itr = S.lower_bound(a);
         if (itr != S.end() && *itr <= b) {
            add(*itr, P);
            add(*itr, K);
            S.erase(itr);
         } else
            break;
      }
   }
   cout << ((sz(S) == 0) ? "YES" : "NO") << endl;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}