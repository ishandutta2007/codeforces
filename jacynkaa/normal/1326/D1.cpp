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
#define rrep(i, a, b) for (int i = a; i < (b); ++i)

const int MAXN = 3e6;
string S;
int tab1[MAXN];
int tab2[MAXN];

// sh = 0 dla palindromow nieparzystych, 1 dla parzystych
// aaaa -> sh=0 [1, 2, 2, 1] sh=1 [0, 1, 2, 1]
void manacher(const char *w, int n, int *p, int sh) {
   int g = 0;
   p[0] = 1 - sh;
   for (int i = 1; i < n; i++) {
      p[i] = 2 * g - i >= 0 ? max(min(p[2 * g - i], p[g] + g - i), 0) : 0;
      while (i >= p[i] + sh && i + p[i] < n && w[i + p[i]] == w[i - p[i] - sh])
         p[g = i]++;
   }
}

void clear() { rep(j, 3 * sz(S)) tab1[j] = tab2[j] = 0; }

string znajdz(string T) {
   clear();
   if (T.size() == 0)
      return "";
   manacher(T.c_str(), sz(T), tab1, 0);
   manacher(T.c_str(), sz(T), tab2, 1);
   for (int k = sz(T) - 1; k >= 0; k--) {
      if (k % 2) {
         if (tab2[(k + 1) / 2] > k / 2)
            return T.substr(0, k + 1);
      } else {
         if (tab1[k / 2] > k / 2)
            return T.substr(0, k + 1);
      }
   }
   exit(-1);
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      cin >> S;
      int n = S.size();
      int idx = 0;
      while (idx < n / 2 && S[idx] == S[n - 1 - idx])
         idx++;
      what(idx);
      string T = S.substr(idx, n - 2 * idx);
      auto P1 = znajdz(T);
      reverse(all(T));
      auto P2 = znajdz(T);
      rep(i, idx) cout << S[i];
      cout << (P1.size() > P2.size() ? P1 : P2);
      rep(i, idx) cout << S[S.size() - (idx - i)];
      cout << endl;
   }
}