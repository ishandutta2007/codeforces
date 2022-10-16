#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
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
 
#define int long long
 
bool valid(pii A) { return A.st <= A.nd; }
 
const int K = 25;
 
int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
 
      int n, k;
      cin >> n >> k;
      string S;
      cin >> S;
      int obciete = max(k - K, 0ll);
      int pozostale = min(K, k);
      string result;
      rep(i, obciete) result.push_back('0');
 
      debug(result, obciete, pozostale);
 
      int ile_jedynek = 0;
      set<int> X;
      rep(i, sz(S)) {

         debug(ile_jedynek);
         if (ile_jedynek >= obciete && i + pozostale <= sz(S)) {
            auto str = S.substr(i, pozostale);
            debug(str);
            X.insert(stoi(str, 0, 2));
         }
                  if (S[i] == '0')
            ile_jedynek = 0;
         else
            ile_jedynek++;
      }
      debug(X);
      if (sz(X) == (1 << pozostale)) {
         cout << "NO\n";
         continue;
      }
 
      vector<int> G(all(X));
      debug(G);
 
      while (pozostale > 0) {
         vector<int> S0;
         vector<int> S1;
         // debug(pozostale, G);
 
         pozostale--;
         for (int s : G) {
            if (s & (1 << pozostale))
               S1.push_back(s ^ (1 << pozostale));
            else
               S0.push_back(s);
         }
         //  debug(S1, S0);
         if (sz(S1) == (1 << (pozostale))) {
            result.push_back('1');
            G = S0;
         } else {
            result.push_back('0');
            G = S1;
         }
      }
      cout << "YES\n";
      cout << result << endl;
   }
}