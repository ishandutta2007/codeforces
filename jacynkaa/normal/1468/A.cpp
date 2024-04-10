#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
// mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
// struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
// gp_hash_table<long long, int, custom_hash> safe_hash_table; -szybsza hashmapa

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
#define debug(...)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     \
   if (false)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \
   cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)

struct drzewo_przedzialowe // drzewo przedzial-przedzial dodaj-dodaj
{
   int rozmiar;
   vector<int> L, P, S;

   int pot(int n) {
      int x = 1;
      while (n > x)
         x = x * 2;
      return x;
   }

   drzewo_przedzialowe(int x) // x-rozmiar drzewa
   {
      rozmiar = pot(x);
      S.resize(2 * rozmiar, 0);
      L.resize(2 * rozmiar);
      P = L;

      for (int i = rozmiar; i < 2 * rozmiar; i++)
         L[i] = P[i] = i - rozmiar;

      for (int i = rozmiar - 1; i > 0; i--) {
         L[i] = L[2 * i];
         P[i] = P[2 * i + 1];
      }
   }

   void set(int p, int x) // dodaje o_ile_zmienic na przedziale [p,q]
   {
      p += rozmiar;
      while (p > 0) {
         S[p] = max(S[p], x);
         p /= 2;
      }
   }
   int get(int p, int q, int wezel = 1) // zwraca sume na przedziale [p,q]
   {
      if (p > q)
         return -1e6;
      if (p == L[wezel] && q == P[wezel])
         return S[wezel];

      return max(get(p, min(P[2 * wezel], q), 2 * wezel), get(max(L[2 * wezel + 1], p), q, 2 * wezel + 1));
   }
};

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      int n;
      cin >> n;
      vector<int> X(n);
      vector<pii> Q;
      set<int> S;
      drzewo_przedzialowe D(n + 2);
      rep(i, n) {
         cin >> X[i];
         S.insert(i);
         Q.push_back({X[i], i});
      }
      sort(all(Q));
      for (auto q : Q) {
         S.erase(q.nd);
         int a1 = D.get(0, q.nd) + 1;
         debug(q);
         auto ptr = S.lower_bound(q.nd);
         int a2 = -1e6;
         if (ptr != S.begin()) {
            int b = *(--ptr);
            debug(b);
            a2 = D.get(0, b) + 2;
         }
         debug(a1, a2);
         D.set(q.nd, max(a1, a2));
      }
      rep(i, n) debug(i, D.get(i, i));
      cout << D.get(0, n + 1) << endl;
   }
}