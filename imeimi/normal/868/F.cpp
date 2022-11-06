#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;

int n;
int hard[100001];
llong _dp1[100001];
llong _dp2[100001];

int cnt[100001];
llong sum = 0ll;
int l = 0, r = 0;

struct dps {
	int s, e, x, y;
};

void add(int i) {
	sum += cnt[hard[i]];
	++cnt[hard[i]];
}

void del(int i) {
	--cnt[hard[i]];
	sum -= cnt[hard[i]];
}

int pro_dp(llong * dp1, llong * dp2, int s, int e, int x, int y) {
	int m = (s + e) / 2;
	int k = x;
	llong v = 1e18;
	while (r < m) add(++r);
	while (m < r) del(r--);
	for (int i = x; i <= y && i < m; ++i) {
		while (l < i) del(++l);
		while (i < l) add(l--);
		if (dp1[i] + sum < v) {
			k = i;
			v = dp1[i] + sum;
		}
	}
	dp2[m] = v;
	return k;
}

void pro_dnc(llong * dp1, llong * dp2, int ks) {
	queue<dps> q;
	q.push({ ks, n, ks - 1, n - 1 });
	while (!q.empty()) {
		dps f = q.front();
		q.pop();
		if (f.s > f.e) continue;
		int k = pro_dp(dp1, dp2, f.s, f.e, f.x, f.y);
		int m = (f.s + f.e) / 2;
		q.push({ f.s, m - 1, f.x, k });
		q.push({ m + 1, f.e, k, f.y });
	}
}

int main() {
	int k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", hard + i);
		add(++r);
		_dp1[i] = sum;
	}
	llong *dp1 = _dp1, *dp2 = _dp2, *t;
	for (int i = 1; i < k; ++i) {
		pro_dnc(dp1, dp2, i + 1);
		t = dp1;
		dp1 = dp2;
		dp2 = t;
	}
	printf("%lld\n", dp1[n]);
	return 0;
}