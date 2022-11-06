#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>

using namespace std;
typedef long long llong;
typedef pair<int, int> pi;

int n, k;
int a[500001];
int b[500001];

pair<llong, int> getAns(llong c) {
	priority_queue<llong> pq1, pq2;
	pq2.push(-4e18);
	llong val = 0ll;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		pq1.push(-a[i]);
		llong t1 = -pq1.top(), t2 = pq2.top();
		llong tb = b[i] + c;
		if (0 <= t1 + tb && t2 <= tb) continue;
		if (t1 + t2 < 0) {
			++cnt;
			val += t1 + tb;
			pq1.pop();
		}
		else {
			val += tb - t2;
			pq2.pop();
		}
		pq2.push(tb);
	}
	return{ val, cnt };
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i), a[i] <<= 1;
	for (int i = 1; i <= n; ++i) scanf("%d", b + i), b[i] <<= 1;
	llong s = 0, e = 2e9 + 1, m;
	int l = 0, r = n;
	llong lval, rval, ans;
	while (s <= e) {
		int cnt; llong val;
		m = (s + e) / 2;
		llong p = m << 1 | 1;
		tie(val, cnt) = getAns(-p);
		if (cnt == k) {
			ans = (val + p * cnt) / 2;
			printf("%lld\n", ans);
			return 0;
		}
		if (cnt < k) {
			if (l <= cnt) {
				l = cnt;
				lval = (val + p * cnt) / 2;
			}
			s = m + 1;
		}
		else {
			if (cnt <= r) {
				r = cnt;
				rval = (val + p * cnt) / 2;
			}
			e = m - 1;
		}
	}
	ans = lval + (rval - lval) / (r - l) * (k - l);
	printf("%lld\n", ans);
	return 0;
}