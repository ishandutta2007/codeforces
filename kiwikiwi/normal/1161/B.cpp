#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 223456

int n, m;
pair<int, int> p[maxN], q[maxN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	auto normalize = [&](pair<int, int> *p, int m) {
		for (int i = 0; i < m; i++) {
			p[i].first %= n;
			p[i].second %= n;
			if (p[i].first > p[i].second)
				swap(p[i].first, p[i].second);
		}
		sort(p, p + m);
	};
	normalize(p, m);
	for (int i = 1; i < n; i++) if (n % i == 0) {
			for (int j = 0; j < m; j++) {
				q[j].first = p[j].first + i;
				q[j].second = p[j].second + i;
			}
			normalize(q, m);
			bool identical = 1;
			for (int j = 0; j < m; j++) {
				identical &= p[j] == q[j];
			}
			if (identical) {
				printf("Yes\n");
				return 0;
			}
		}
	printf("No\n");
}