#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

int bad[5] = {0, 2, 3, 4, 1};

int smjer(int a, int b, int x, int y) {
   if(a == x) {
      if(y > b) {
         return 2;
      }
      return 4;
   }
   if(x > a) {
      return 1;
   }
   return 3;
}

int x, y, X, Y;

int old, sol;

int main() {
   int n; cin >> n;

   cin >> x >> y;

   rep(i, n) {
      cin >> X >> Y;
      int NEW = smjer(x, y, X, Y);
      if(bad[old] == NEW) sol++;
      x = X; y = Y; old = NEW;
   }

   cout << sol;
}