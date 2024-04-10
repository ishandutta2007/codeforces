#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
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
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
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
#define int long long

vector<int> res;
set<int> S;
map<int, int> M;

int get_next(int x, set<int> &S) {
   if (S.empty())
      return -1;

   auto itr = S.lower_bound(x);

   if (itr == S.end())
      return *S.begin();

   return *itr;
}

int get_next(int x, map<int, int> &M) {
   if (M.empty())
      return -1;

   auto itr = M.upper_bound(x);

   if (itr == M.end())
      return M.begin()->st;

   return itr->st;
}

void del(int x) {
   S.erase(x);
   int a = get_next(x, M);
   debug(a);

   res.push_back(a);
   M.erase(a);
   S.erase(a);

   if (a == x)
      return;

   a = get_next(x, M);
   if (__gcd(M[a], M[x]) == 1)
      S.insert(x);
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {

      M.clear();
      res.clear();
      S.clear();

      int n;
      cin >> n;
      rep(i, n) cin >> M[i];
      rep(i, n) if (__gcd(M[i], M[(i + 1) % n]) == 1) S.insert(i);

      int idx = 0;

      while (sz(S) > 0) {
         debug(S);
         idx = get_next(idx, S);
         debug(idx);
         del(idx);
         idx++;
      }

      cout << sz(res) << " ";
      for (int a : res)
         cout << a + 1 << " ";
      cout << endl;
   }
}