#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep1(i, n) for(int i = 1; i < n; ++i)
#define _ << " " <<

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 2e5 + 5, M = 1e9 + 7, p1 = 105023, p2 = 15486277, p3 = 179425033;

vector<int> S, X;

ll sol;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   ll s, x;

   cin >> s >> x;

   if(s == x)
      sol = 2;

   while(s) {
      S.push_back(s % 2);
      s >>= 1;
   }

   while(x) {
      X.push_back(x % 2);
      x >>= 1;
   }

   if(X.size() > S.size()) {
      cout << 0;
      return 0;
   }

   int n = X.size(), m = S.size();

   for(int j = n; j <= m; ++j)
      X.push_back(0);

   ll i = 1, p = 0;

   for(int t = 0; t < m; ++t) {
      int sb = S[t], xb = X[t];

      if(sb && xb) {
         i *= 2;
         p = 0;
      }
      if(sb && !xb) {
         p = p;
         i = p;
      }
      if(!sb && xb) {
         p *= 2;
         i = 0;
      }
      if(!sb && !xb) {
         p = i;
         i = i;
      }
   }

   cout << i - sol;

}