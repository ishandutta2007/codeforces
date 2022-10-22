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

const int MAXN = 2e5 + 5;

int a[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int n; cin >> n;
   rep(i, n) {
      char c; cin >> c;
      if(c == '<') a[i] = 1;
   }

   int sol = 0;
   rep(i, n) {
      if(a[i] == 1) {
         sol ++;
      }
      else {
         break;
      }
   }
   for(int i = n - 1; i >= 0; --i) {
      if(a[i] == 0) {
         sol ++;
      }
      else {
         break;
      }
   }
   cout << sol;
}