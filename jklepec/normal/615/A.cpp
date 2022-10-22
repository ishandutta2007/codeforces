#include <bits/stdc++.h>
#define mid ((lo + hi) >> 1)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a) for(int i = 0; i < a; ++i)
using namespace std;

typedef long long llint;
typedef pair<int, int> point;

const int MAXN = 1001;

bool light[MAXN];

int main() {
   int n, m; cin >> n >> m;
   for(int i = 0; i < n; ++i) {
      int x; cin >> x;
      for(int j = 0; j < x; ++j) {
         int y; cin >> y;
         light[y] = true;
      }
   }
   for(int i = 0; i < m; ++i) {
      if(!light[i + 1]) {
         cout << "NO";
         return 0;
      }
   }
   cout << "YES";
   return 0;
}