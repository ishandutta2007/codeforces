#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int main() {
	int n, w;
	scanf("%d%d", &n, &w);

	priority_queue<pair<int, int> > pq1, pq2;
	static int t[600000];

	for (int i = 0; i < n; ++ i) {
		int a, b;
		scanf("%d%d", &a, &b);
		pq1.push(make_pair(- a, i));
		pq2.push(make_pair(- b, i));
		t[i] = a, t[i + n] = b - a;
	}

	long long ans = 0;
	static int used[600000], opt[300000];
	memset(used, 0, sizeof used);

	while (w --) {
		while (pq1.size() && used[pq1.top().second]) pq1.pop();
		while (pq2.size() && used[pq2.top().second]) pq2.pop();
		pair<int, int> now = pq1.top();
		pq1.pop();
		while (pq1.size() && used[pq1.top().second]) pq1.pop();
		int toUse;
		if (! w || pq2.empty() || - pq2.top().first > - now.first - pq1.top().first)
			toUse = now.second;
		else {
			toUse = pq2.top().second;
			pq2.pop();
			pq1.push(now);
		}
		ans += t[toUse];
		if (toUse >= n) opt[toUse - n] = 2; else opt[toUse] = 1;
		used[toUse] = 1;
		if (toUse < n) pq1.push(make_pair(- t[toUse + n], toUse + n));
	}

	cout << ans << endl;
	for (int i = 0; i < n; ++ i)
		printf("%d", opt[i]);
	return 0;
}