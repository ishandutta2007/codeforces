#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
ll a[N], b[N];
int n;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%lld", b + i);
	a[1] = b[1]; ll mx = a[1];
	for(int i = 2; i <= n; i ++) {
		mx = max(mx, a[i - 1]);
		a[i] = mx + b[i];
	}
	for(int i = 1; i <= n; i ++) printf("%lld ", a[i]);
	return 0;
}