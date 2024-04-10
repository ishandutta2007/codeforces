#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;

int add(int x, int y) {
   x += y;
   if(x >= mod) x -= mod;
   return x;
}
int mul(int x, int y) {
   return (ll) x * y % mod;
}
int sub(int x, int y) {
   x -= y;
   if(x < 0) x += mod;
   return x;
}

const int MAXN = 1e5 + 5;
int took[MAXN];

vector<int> a1, b1;

vector<int> sup[MAXN];
vector<point> veze;

void take(int x, int y) {
   took[x] = y;
   for(auto z : sup[x])
      if(!took[z])
         take(z, 3 - y);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n, m; cin >> n >> m;
   rep(i, m) {
      int x, y; cin >> x >> y;
      sup[x].push_back(y);
      sup[y].push_back(x);
      veze.push_back({x, y});
      /*if(!took[x] && !took[y]) {
         took[x] = 1;
         took[y] = 2;
      }
      if(took[x] == took[y]) {
         cout << -1;
         return 0;
      }
      if(took[x]) {
         if(!took[y]) {
            took[y] = 3 - took[x];
         }
      }
      if(took[y]) {
         if(!took[x]) {
            took[x] = 3 - took[y];
         }
      }*/
   }
   rep(j, n) {
      int i = j + 1;
      if(!took[i]) {
         take(i, 1);
      }
   }
   rep(i, n) {
      if(took[i + 1] == 1) {
         a1.push_back(i + 1);
      }
      else {
         b1.push_back(i + 1);
      }
   }
   for(auto p : veze) {
      if(took[p.first] + took[p.second] != 3) {
         cout << -1;
         return 0;
      }
   }
   cout << a1.size() << endl;
   for(auto x : a1)
      cout << x << " ";
   cout << endl << b1.size() << endl;
   for(auto x : b1)
      cout << x << " ";


}