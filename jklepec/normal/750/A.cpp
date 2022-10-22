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

	int n, k; cin >> n >> k;
   for(int i = n; i >= 0; --i) {
      if(i * (i + 1) / 2 * 5 + k <= 240) {cout << i; break;}
   }
}