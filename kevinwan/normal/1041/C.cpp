#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
pii a[200000];
int up[200001],ans[200001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main() {
	int n, m, d, i,cu=1;
	scanf("%d%d%d", &n, &m, &d);
	for (i = 0; i < n; i++)scanf("%d", &a[i].first), a[i].second = i;
	memset(up, -0x3f, sizeof(up));
	sort(a , a + n);
	pq.push({  up[cu],cu }),cu++;
	for (i = 0; i < n; i++) {
		if (pq.top().first+ d >= a[i].first)pq.push({ up[cu],cu}),cu++;
		ans[a[i].second] = pq.top().second;
		pii p = pq.top();
		pq.pop();
		up[p.second] = a[i].first;
		pq.push({ up[p.second], p.second });
	}
	printf("%d\n", cu - 1);
	for (i = 0; i < n; i++)printf("%d ", ans[i]);
	getchar(); getchar();
}