#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
struct Node { int b, p, e; } q[N];
int n, m, up[N];
ll a[N];
bool cmp(int x, int y) { return x > y; }
bool cmp2(Node a, Node b) { return a.e < b.e; }
priority_queue<int> pq;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%I64d", a + i); up[i] = a[i];
		while(i > 1 && up[i - 1] <= up[i]) {
			up[i - 1] = up[i]; a[i - 1] += a[i]; i --; n --;
		}
	}
	for(int i = 1; i <= m; i ++) scanf("%d", &q[i].b);
	for(int i = 1; i <= m; i ++) scanf("%d", &q[i].p);
	for(int i = 1; i <= m; i ++) q[i].e = upper_bound(up + 1, up + n + 1, q[i].b, cmp) - up - 1;
	sort(q + 1, q + m + 1, cmp2);
	int p = 1;
	while(p <= m && q[p].e < 1) p ++;
	ll now = 0, ans = 0;
	for(int i = 1; i <= n; i ++) {
		now += a[i];
		for(; p <= m && q[p].e <= i; p ++) {
			if(now >= q[p].p) {
				now -= q[p].p;
				pq.push(q[p].p); ans ++;
			} else {
				if(pq.size() && pq.top() > q[p].p) {
					now += pq.top();
					pq.pop(); pq.push(q[p].p);
					now -= q[p].p;
				}
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}