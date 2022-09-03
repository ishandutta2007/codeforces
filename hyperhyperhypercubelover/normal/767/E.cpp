#include <cstdio>
#include <queue>

using namespace std;

int a[100001];
int b[100001];
int c[100001];
int u[100001], v[100001];

int main() {
	priority_queue<pair<int, int> > pq;
	long long r = 0;
	int i, j, k, n, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = (m + (100 - a[i] % 100) % 100) / 100;
		u[i] = (a[i] + 99) / 100;
		m += u[i] * 100 - a[i];
	}
	for (i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (i = n; i >= 1; i--) {
		if (a[i] % 100) pq.push({ (100 - a[i] % 100) * c[i], i });
		while (!pq.empty() && b[i] --> b[i - 1]) {
			j = pq.top().second;
			pq.pop();
			u[j]--;
			v[j] = a[j] % 100;
		} 
	}
	while (!pq.empty()) {
		r += pq.top().first;
		pq.pop();
	}
	printf("%lld\n", r);
	for (i = 1; i <= n; i++) printf("%d %d\n", u[i], v[i]);
}