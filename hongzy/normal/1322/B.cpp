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
int n, a[N], b[N], c[N], cnt[10000050], t[10000050];
int main() {
	ucin; cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for(int i = 0; i < 25; i ++) {
		int cur = 0, all = (1 << (i + 1)) - 1;
		for(int j = 1; j <= n; j ++) t[b[j] = a[j] & all] ++;
		int m = *max_element(b + 1, b + n + 1);
		for(int j = 1; j <= m; j ++) t[j] += t[j - 1];
		for(int j = 1; j <= n; j ++) c[t[b[j]] --] = b[j];
		for(int j = 0; j <= m; j ++) t[j] = 0;
		int p1 = n, p2 = n, p3 = n;
		for(int j = 1; j <= n; j ++) {
			while(p1 && c[p1] > (1 << i) - 1 - c[j]) p1 --;
			while(p2 && c[p2] > (1 << (i + 1)) - 1 - c[j]) p2 --;
			while(p3 && c[p3] > (1 << (i + 1)) + (1 << i) - 1 - c[j]) p3 --;
			if((min(p1, j - 1) ^ min(p2, j - 1) ^ min(p3, j - 1) ^ (j - 1)) & 1) cur ^= 1;
		}
		if(cur) ans ^= 1 << i;
	}
	cout << ans << endl;
	return 0;
}