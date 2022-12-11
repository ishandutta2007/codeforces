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
int n, m, suf[N], p[N], ans[N];
ll sum;
pii a[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++) scanf("%d", &a[i].fs), a[i].sc = i, sum += a[i].fs;
	if(sum < n) { puts("-1"); return 0; }
	int len = 0;
	for(int i = 1; i <= m; i ++)
		if(i + a[i].fs - 1 > n) { puts("-1"); return 0; }
	suf[m] = m + a[m].fs - 1;
	for(int i = m - 1; i >= 1; i --) suf[i] = max(suf[i + 1], i + a[i].fs - 1);
	p[1] = 1;
	for(int i = 2; i <= m; i ++) {
		if(len == n) {
			p[i] = p[i - 1] + 1;
			continue ;
		}
		int cur = suf[i] - i + 1;
		p[i] = p[i - 1] + 1;
		int x = max(0, min(n - cur + 1 - p[i], a[i - 1].fs - 1));
		p[i] += x; len += x;
	}
	for(int i = 1; i <= m; i ++) printf("%d ", p[i]);
	return 0;
}