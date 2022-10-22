#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> point;

#define gcd(a, b) __gcd(a, b)
#define all(a) (a).begin(), (a).end()
#define FOR(i, a, b) for(int i = a; i < b; ++i)

const int MAXN = 505;

int E[MAXN][MAXN];
int b[MAXN], e[MAXN];;

bool poss = true;
bool bio[MAXN];

int n;

void dfs(int x) {
   bio[x] = true;
   if(b[x] == 2)
      return;
   FOR(y, 0, n) {
      if(x == y) continue;
      if(abs(b[x] - b[y]) == 2 && E[x][y]) poss = false;
      if(E[x][y])
         if(!b[y])
            b[y] = b[x];
      if(!E[x][y]) {
         if(b[x] == 1 && (b[y] != 3 && b[y] != 0)) poss = false;
         else if(b[x] == 3 && (b[y] != 1 && b[y] != 0)) poss = false;
         else if(b[x] == 1) b[y] = 3;
         else if(b[x] == 3) b[y] = 1;
      }
   }
   FOR(y, 0, n)
      if(!bio[y] && b[y])
         dfs(y);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int m; cin >> n >> m;
   for(int i = 0; i < m; ++i) {
      int x, y; cin >> x >> y; --x; --y;
      E[y][x] = 1;
      E[x][y] = 1;
      e[x] ++;
      e[y] ++;
   }
   for(int i = 0; i < n; ++i)
      if(e[i] == n - 1)
         b[i] = 2;
   for(int i = 0; i < n; ++i) {
      if(!bio[i] && b[i] != 2) {
         b[i] = 1;
         dfs(i);
      }
   }
   if(poss)
      for(int i = 0; i < n; ++i)
         cout << (i ? "" : "Yes\n") << char('a' + b[i] - 1);
   else
      cout << "No\n";
}