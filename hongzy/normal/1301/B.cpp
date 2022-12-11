#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
#define pb push_back 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
int n, a[N], k;
bool ck(int mid) {
	ll l = 0, r = 1e9;
	for(int i = 1; i <= n; i ++) if(~ a[i]) {
		if(a[i + 1] == -1 || a[i - 1] == -1) {
			ll nl = a[i] - mid, nr = a[i] + mid;
			l = max(l, nl); r = min(r, nr);
		}
	}
	if(l <= r) k = l;
	return l <= r;
}
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%d", a + i);
		a[0] = a[n + 1] = 0;
		int l = 0, r = 1e9, mid, ans;
		for(int i = 1; i < n; i ++) if(~ a[i] && ~ a[i + 1])
			l = max(l, a[i] > a[i + 1] ? a[i] - a[i + 1] : a[i + 1] - a[i]);
		while(l <= r) {
			mid = (l + r) >> 1;
			if(ck(mid)) r = (ans = mid) - 1;
			else l = mid + 1;
		}
		ck(ans);
		printf("%d %d\n", ans, k);
	}
	return 0;
}