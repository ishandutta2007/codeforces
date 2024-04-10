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

const int MAXN = 1e5 + 5;
vector<point> sol;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int n; cin >> n;
   int nula =  0, nenula = 0, l = 0;
   rep(i, n) {
      int x; cin >> x;
      if(x != 0) {
         if(nenula) {
            nenula = 1;
            sol.push_back(point(l, i - 1));
            l = i;
         }
         else {
            nenula ++;
         }
      }
   }
   if(nenula) {
      sol.push_back(point(l, n - 1));
   }
   else if(l != n) {
      cout << "NO";
      return 0;
   }
   cout << "YES\n";
   cout << sol.size();
   for(auto p : sol) cout << endl << p.first + 1 << ' ' << p.second + 1;
}