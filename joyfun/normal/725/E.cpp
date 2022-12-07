#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int n, c, x[N];
ll sum[N];
int val, vi;

int getx(int v) {
	if (v == vi + 1) return val;
	if (v > vi) return x[v - 1];
	return x[v];
}

ll getsum(int v) {
	if (v > vi) return sum[v - 1] + val;
	return sum[v];
}

bool judge() {
	vi = lower_bound(x + 1, x + 1 + n, val) - x - 1;
	int la = n + 1, cc = c;
	while (la && cc) {
		int l = 0, r = la;
		while (l < r) {
			int mid = (l + r)>>1;
			if (getsum(la) - getsum(mid) > cc) l = mid + 1;
			else r = mid;
		}
		if (l == la) break;
		cc -= getsum(la) - getsum(l);
		r = l + 1, l = 0;
		while (l < r) {
			int mid = (l + r)>>1;
			if (getx(mid) > cc) r = mid;
			else l = mid + 1;
		}
		la = l - 1;
	}
	return cc != 0;
}

int main() {
	scanf("%d%d", &c, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + x[i];
	for (int i = 1; i <= c; i++) {
		val = i;
		if (judge()) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("Greed is good\n");
	return 0;
}