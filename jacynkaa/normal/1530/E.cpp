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
#define debug(...) 42
#endif

#define emp 0

char poj(map<char, int> &M) {

   for (auto [c, i] : M)
      if (i == 1)
         return c;

   return emp;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      string R;
      cin >> R;
      const string S = R;
      map<char, int> M;
      for (char c : S)
         M[c]++;

      auto cc = poj(M);

      if (cc != emp) {
         debug("POJEDYNCZA LITERKA");
         string S = {cc};
         for (auto [c, i] : M)
            if (c != cc)
               while (i--)
                  S.push_back(c);
         cout << S << endl;
         continue;
      }

      if (sz(M) == 1) {
         debug("JEDNA");
         cout << S << endl;
         continue;
      }

      string S2;

      cc = M.begin()->st;
      int r = M[cc];

      for (auto [c, i] : M)
         if (c != cc)
            while (i--)
               S2.push_back(c);

      if (r - 2 <= sz(S2)) {
         debug("sz(S1) - 2 <= r");

         reverse(all(S2));
         string res = {cc, cc};

         while (sz(S2)) {
            res.push_back(S2.back());
            S2.pop_back();
            if (r - 2) {
               r--;
               res.push_back(cc);
            }
         }
         cout << res << endl;
         assert(sz(res) == sz(S));

      } else {
         if (sz(M) == 2) {
            debug("M==2");
            string res = {cc};
            res += S2;
            rep(i, r - 1) res.push_back(cc);
            cout << res << endl;
            assert(sz(res) == sz(S));

         } else {
            debug("RESZTA");
            auto itr = M.begin();
            auto c1 = (++itr)->st;
            auto c2 = (++itr)->st;
            M[c1]--, M[c2]--;
            string res = {cc, c1};
            rep(i, r - 1) res.push_back(cc);
            res.push_back(c2);

            for (auto [c, i] : M)
               if (c != cc)
                  while (i--)
                     res.push_back(c);
            assert(sz(res) == sz(S));
            cout << res << endl;
         }
      }
   }
}