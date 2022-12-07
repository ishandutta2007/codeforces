#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 300005;
typedef long long ll;

int n;

struct SB {
	ll t, w;
	void read() {
		scanf("%lld%lld", &t, &w);
	}
	bool operator < (const SB& c) const {
		return w - t > c.w - c.t;
	}
} sb[N], o;

bool cmp(SB a, SB b) {
	return a.t > b.t;
}

priority_queue<SB> Q;

int main() {
	scanf("%d", &n);
	o.read(); n--;
	for (int i = 0; i < n; i++) sb[i].read();
	sort(sb, sb + n, cmp);
	int i = 0;
	int ans = n + 1;
	while (1) {
		while (i < n && sb[i].t > o.t) {Q.push(sb[i]); i++;}
		ans = min(ans, (int)Q.size() + 1);
		if (Q.size() == 0) break;
		SB u = Q.top();
		if (u.w - u.t + 1 <= o.t) {
			o.t -= u.w - u.t + 1;
			Q.pop();
		} else break;
	}
	printf("%d\n", ans);
	return 0;
}