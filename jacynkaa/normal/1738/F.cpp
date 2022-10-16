#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
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

typedef vector<int> vi;

struct UF {
   vi e;
   UF(int n) : e(n, -1) {}
   bool same_set(int a, int b) { return find(a) == find(b); }
   int size(int x) { return -e[find(x)]; }
   int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
   bool join(int a, int b) {
      a = find(a), b = find(b);
      if (a == b)
         return false;
      if (e[a] > e[b])
         swap(a, b);
      e[a] += e[b];
      e[b] = a;
      return true;
   }
};

int query(int a) {
   cout << "? " << a + 1 << endl;
   cin >> a;
   return --a;
}

void ans(vector<int> &A) {
   cout << "! ";
   for (int a : A)
      cout << a << " ";
   cout << endl;
}

void solve() {
   int n;
   cin >> n;

   vector<int> D(n);
   set<int> V;
   UF U(n);
   vector<int> I(n);
   rep(i, n) I[i] = i;
   rep(i, n) cin >> D[i];

   sort(all(I), [&](auto a, auto b) { return D[a] > D[b]; });

   debug(I);

   debug(I);

   for (int i : I)
      if (V.count(i) == 0) {
         V.insert(i);
         while (D[i]--) {
            int a = query(i);
            U.join(i, a);
            if (V.count(a))
               break;
            V.insert(a);
         }
      }
   vector<int> A(n);
   rep(i, n) A[i] = U.find(i) + 1;
   ans(A);
}

int32_t main() {
   int Z;
   cin >> Z;
   while (Z--)
      solve();
}