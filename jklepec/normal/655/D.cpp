#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define x first
#define y second

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 1e5 + 5, M = 1e9 + 7;

vector<point> v;

int o[MAXN];

int n, m;

bool check(int k) {
   if(k == m + 1) return true;

   memset(o, 0, sizeof o);
   vector<int> e[MAXN];

   rep(i, k) {
      e[v[i].x].push_back(v[i].y);
      o[v[i].y]++;
   }

   queue<int> Q;
   rep(i, n) if(o[i] == 0) Q.push(i);

   int used = 0;

   while(Q.size() == 1) {
      used ++;
      int x = Q.front();

      for(auto y : e[x]) {
         o[y] --;
         if(o[y] == 0) Q.push(y);
      }
      Q.pop();
   }

   return used == n;
}

int main() {

   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   cin >> n >> m;

   rep(i, m) {
      int x, y; cin >> x >> y;
      v.push_back({--x, --y});
   }

   int lo = 1, hi = m + 1;

   while(lo < hi) {
      int mid = (lo + hi) >> 1;
      if(check(mid))
         hi = mid;
      else
         lo = mid + 1;
   }

   cout << (lo == m + 1 ? -1 : lo);
}