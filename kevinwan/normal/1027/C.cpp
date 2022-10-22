#include <bits/stdc++.h>
using namespace std;
map<int, int> a;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, i, x;
		scanf("%d", &n);
		vector<int> v;
		a.clear();
		for (i = 0; i < n; i++)scanf("%d", &x), a[x]++;
		bool flag = 0;
		for (pair<int,int> p:a) {
			if (p.second >= 4) {
				i = p.first;
				printf("%d %d %d %d\n", i, i, i, i); flag = 1;
				break;
			}
		}
		if (flag)continue;
		for (pair<int, int> p : a)if(p.second>=2)v.push_back(p.first);
		int num = 1, den = 0;
		for (i = 0; i <v.size() - 1; i++) {
			if (v[i + 1] * den <= num * v[i])num = v[i + 1], den = v[i];
		}
		printf("%d %d %d %d\n", num, den, den, num);
	}
	getchar(); getchar();
}/*
int c[200001], a[200001],p[200001],ans[200001];
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", c + i);
	for (i = 1; i <= n; i++) scanf("%d", a + i);
	for (i = 1; i <= n; i++) {
		if (p[i] != 0)continue;
		p[i] = i;
		int x = a[i];
		while (x != i) {
			p[x] = i;
			x = a[x];
		}
	}
	memset(ans, 0x3f, sizeof(ans));
	for (i = 1; i <= n; i++)ans[p[i]] = min(ans[p[i]], c[i]);
	int ret = 0;
	for (i = 1; i <= n; i++)if (ans[i] != 0x3f3f3f3f)ret += ans[i];
	printf("%d", ret);
}*/