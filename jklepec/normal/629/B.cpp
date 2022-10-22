#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

#define FOR(i, a, b) for(int i = a; i < b; ++i)

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

int m[500], f[500];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);

   int n; cin >> n;

   int sol = 0;

   FOR(i, 0, n) {
      char c;
      cin >> c;

      int x, y;
      cin >> x >> y;

      if(c == 'M')
         FOR(i, x, y + 1)
            m[i] ++;
      else
         FOR(i, x, y + 1)
            f[i] ++;
   }

   FOR(i, 1, 367) {
      sol = max(min(f[i], m[i]) * 2, sol);
   }

   cout << sol;

}