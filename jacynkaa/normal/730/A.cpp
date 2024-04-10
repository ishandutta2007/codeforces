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

// void add(vector<vector<int>> &V, vector<int> X) {
//    int s = 0;
//    if (sz(X) % 2 == 1) {
//       V.push_back({X[0], X[1], X[2]});
//       s = 3;
//    }

//    for (int i = s; i < sz(X); i += 2)
//       V.push_back({X[2 * i], X[2 * i + 1]});
// }

// vector<vector<int>> solve(map<int, vector<int>> M) {
//    vector<vector<int>> res;
//    while (!M.empty()) {
//       if (M.rbegin()->nd.size() > 1) {
//          auto [i, V] = *M.rbegin();
//          add(res, V);
//       } else {
//          if (sz(M) == 1)
//             return {};
//          auto [i, V] = M;
//          auto itr = M.end();
//          itr--;
//          itr--;
//          auto i = itr->st;
//          auto x = itr->nd.back();
//          add(res, {M[i][0], x});
//          M[]
//       }
//       M.erase(i);
//       for (int x : V)
//          M[i - 1].push_back(x);

//       M.erase(0);
//    }
// }

vector<set<int>> get(set<pii> &S) {
   vector<set<int>> res;
   while (sz(S) > 1) {
      auto itr = S.end();
      auto [a, b] = *(--itr);
      S.erase(itr);
      itr = S.end();
      auto [c, d] = *(--itr);
      S.erase(itr);
      res.push_back({b, d});

      if (a > 1)
         S.insert({a - 1, b});
      if (c > 1)
         S.insert({c - 1, d});
   }

   if (sz(S)) {
      auto [a, b] = *S.begin();
      if (a != 1)
         return {};
      for (auto &s : res)
         if (s.count(b) == 0) {
            s.insert(b);
            return res;
         }
      return {};
   }
   return res;
}

int32_t main() {
   _upgrade;
   int n;
   cin >> n;
   vector<int> A(n);
   rep(i, n) cin >> A[i];

   for (int R = *min_element(all(A)); R > 0; R--) {
      set<pii> S;
      rep(i, n) {
         auto a = A[i] - R;
         if (a)
            S.insert({a, i});
      }
      auto res = get(S);
      if (sz(S) == 0 || sz(res)) {
         debug(res);
         cout << R << endl;
         cout << sz(res) << endl;

         for (auto &s : res) {
            rep(i, n) cout << (s.count(i));
            cout << endl;
         }
         exit(0);
      }
   }
   cout << 0 << endl;
   cout << (n - 1) * 100 << endl;
   for (int i = 1; i < n; i++) {
      rep(j, 100) {
         rep(k, n) cout << ((k == i || k == 0) ? 1 : 0);
         cout << endl;
      }
   }
}