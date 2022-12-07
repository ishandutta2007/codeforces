#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

int n, k, p[15], vis[15];
ll f[15];
map<int, int> v;

bool judge(int x) {
	while (x) {
		if (x % 10 != 4 && x % 10 != 7) return false;
		x /= 10;
	}
	return true;
}

int main() {
	f[0] = 1;
	for (int i = 1; i < 15; i++) f[i] = f[i - 1] * i;
	scanf("%d%d", &n, &k); k--;
	int len = min(13, n);
	for (int i = 1; i <= len; i++) {
		int j;
		for (j = 1; j <= len; j++) {
			if (vis[j]) continue;
			if (k < f[len - i]) {
				p[i] = j;
				vis[j] = 1;
				break;
			}
			k -= f[len - i];
		}
		if (j > len) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = n; i > n - len; i--) v[i] = p[i - (n - len)] + n - len;
	int ans = 0;
	for (int b = 1; b <= 10; b++) {
		for (int i = 0; i < (1<<b); i++) {
			ll x = 0;
			for (int j = 0; j < b; j++) 
				x = x * 10 + (((i>>j)&1) ? 4 : 7);
			if (x >= 1 && x <= n) {
				if (v.count(x)) ans += judge(v[x]);
				else ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}