#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
#pragma GCC optimize("-O3")
using namespace std;
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

vector<int> A;
int n;
int res;

inline bool isPlus(int i) { return i > 0 && i < n - 1 && ((A[i] > A[i - 1] && A[i] > A[i + 1]) || (A[i] < A[i - 1] && A[i] < A[i + 1])); }

void add(int i) {
   for (int j = max(0, i - 1); j <= min(n - 1, i + 1); j++)
      res += isPlus(j);
}

void remove(int i) {
   for (int j = max(0, i - 1); j <= min(n - 1, i + 1); j++)
      res -= isPlus(j);
}

int solve(int i) {
   int wynik = res;
   int tmp = A[i];
   remove(i);
   A[i] = A[i - 1];
   add(i);
   wynik = min(wynik, res);
   remove(i);
   A[i] = A[i + 1];
   add(i);
   wynik = min(wynik, res);
   remove(i);
   A[i] = tmp;
   add(i);
   return wynik;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      cin >> n;
      A.resize(n);
      res = 0;
      rep(i, n) cin >> A[i];
      rep(i, n) res += isPlus(i);
      debug(res);
      int wynik = res;
      rep(i, n) wynik = min(solve(i), wynik);
      debug(A);
      cout << wynik << endl;
   }
}