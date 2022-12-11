#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define fs first
#define sc second
const int N = 1e5 + 10;
const int mo = 1e9 + 7;
int qpow(int a, int b) {
	int ans = 1; a = (a % mo + mo) % mo;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = 1ll * ans * a % mo;
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	cout << qpow(qpow(2, m) - 1, n) << endl;
	return 0;
}