#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long llint;
typedef pair<int, int> point;

const int MAXN = 2020;

llint x, y;
llint x2, y2;

llint dist(llint a, llint b) {
   return abs(a - x) * abs(a - x) + abs(b - y) * abs(b - y);
}

llint dist2(llint a, llint b) {
   return abs(a - x2) * abs(a - x2) + abs(b - y2) * abs(b - y2);
}

llint X[MAXN], Y[MAXN];

int main() {
   int n; cin >> n;
   cin >> x >> y;
   cin >> x2 >> y2;
   llint sol = 0;
   for(int i = 0; i < n; ++i) {
      cin >> X[i] >> Y[i];
      sol = max(sol, dist2(X[i], Y[i]));
   }
   for(int i = 0; i < n; ++i) {
      llint k = dist(X[i], Y[i]);
      llint k2 = 0LL;
      for(int j = 0; j < n; ++j) {
         if(dist(X[j], Y[j]) <= k)
            continue;
         k2 = max(k2, dist2(X[j], Y[j]));
      }
      sol = min(k + k2, sol);
   }
   cout << sol;
   return 0;
}