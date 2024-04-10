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

int idx(int i, string S) {
   for (int k = i; k < sz(S); k++)
      if (S[k] == '#')
         return k;
   return sz(S) + 1;
}

string get(string S, int a) {
   debug(S, a);

   for (int i = a; i < sz(S);) {
      if (S[i] == '_') {

         int k = idx(i, S);
         debug(i, k);

         if (k == i + 1)
            return "";

         for (int l = i; l < k - 1 && l < sz(S); l += 2)
            S[l] = '#';

         if (k - 2 >= 0 && k - 2 <= sz(S))
            S[k - 2] = '#';

         i = k;

      } else {
         while (i < sz(S) && S[i] == '#')
            i++;

         for (int k = i; k < i + a; k++)
            if (k >= sz(S))
               return "";
            else
               S[k] = '#';
         i = i + a + 1;
      }
   }
   S.back() = '#';
   return S;
}

string get_zlozenie(string S, int a) {
   if (a >= sz(S))
      return "";

   string res = S;

   rep(i, a) if (S[i] == '#') return "";

   rep(i, a) S.push_back('_');

   for (int b = 1; b <= a; b++)
      for (int i = b; i < sz(S); i++)
         if (S[i] == '_' && i - b < sz(res))
            res[i - b] = '_';

   return res;
}

void ans(string S) {

   vector<int> X(1);

   for (auto c : S)
      if (c == '_')
         X.push_back(0);
      else
         X.back()++;

   vector<int> res;
   for (auto x : X)
      if (x != 0)
         res.push_back(x);

   cout << sz(res) << endl;
   for (int x : res)
      cout << x << " ";
   cout << endl;

   exit(0);
}

int32_t main() {
   _upgrade;

   string S;
   cin >> S;
   debug(S);

   if (count(all(S), '#') == 0) {
      cout << 0 << endl;
      exit(0);
   }

   for (int a = 0; a <= 3 && a < sz(S); a++) {
      auto T = get(S, a);

      if (sz(S) != sz(T))
         continue;

      debug(T);
      auto Z = get_zlozenie(T, a);
      debug(Z);
      if (Z == S)
         ans(T);
   }

   cout << -1 << endl;
}