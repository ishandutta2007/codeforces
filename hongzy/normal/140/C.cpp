#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

#define pb push_back

const int N = 1e5 + 10;

struct Node {
	int cnt, u;
	bool operator < (const Node &b) const {
		return cnt < b.cnt;
	}
};

int n, a[N];
priority_queue<Node> pq;
vector<int> res[3];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	int cnt = 1;
	for(int i = 2; i <= n; i ++) {
		if(a[i] == a[i - 1]) cnt ++;
		else {
			pq.push((Node) {cnt, a[i - 1]}); cnt = 1;
		}
	}
	if(cnt) pq.push((Node) {cnt, a[n]});
	int ans = 0;
	while(pq.size() >= 3) {
		Node x = pq.top(); pq.pop();
		Node y = pq.top(); pq.pop();
		Node z = pq.top(); pq.pop();
		if(-- x.cnt >= 1) pq.push(x);
		if(-- y.cnt >= 1) pq.push(y);
		if(-- z.cnt >= 1) pq.push(z);
		ans ++;
		res[0].pb(x.u);
		res[1].pb(y.u);
		res[2].pb(z.u);
	}
	printf("%d\n", ans);
	for(int i = 0; i < ans; i ++) {
		a[0] = res[0][i]; a[1] = res[1][i]; a[2] = res[2][i];
		sort(a, a + 3);
		printf("%d %d %d\n", a[2], a[1], a[0]);
	}
	return 0;
}