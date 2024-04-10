#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if(x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if(x < 0) return x + mod;
	return x;
}
int mul(int x, int y) {
	return (ll) x * y % mod;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int x = 0;

	int n; cin >> n;
	for(int i = 0; i < n; ++i) {
      int v; string s; cin >> v >> s;
      if((s == "East" || s == "West") && (x == 0 || x == 20000)) {
         cout << "NO";
         return 0;
      }
      if(s == "East" || s == "West") continue;
      if(s == "North") {
         x -= v;
         if(x < 0) {
            cout << "NO";
            return 0;
         }
      }
      if(s == "South") {
         x += v;
         if(x > 20000) {
            cout << "NO";
            return 0;
         }
      }
	}

	if(x == 0) cout << "YES";
	else cout << "NO";
}