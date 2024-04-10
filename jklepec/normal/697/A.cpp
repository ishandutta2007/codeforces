#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5, mod = 1e9 + 7;

int n;

void load() {
   int t, s, x;
   cin >> t >> s >> x;
   if(x == t) {
      cout << "YES";
      return;
   }
   if(x > t) {
      x -= t;
      if(x % s == 0 || (x - 1) % s == 0 && x != 1) {
         cout << "YES";
         return;
      }
   }

   cout << "NO";
}

void solve() {

}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   load();
   solve();
}