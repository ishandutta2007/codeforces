#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100000], b[100000];
map<int, int> t;
int main() {
	int n, m,i,j,y;
	scanf("%d%d", &n,&y);
	for (i = 0; i < n; i++)scanf("%d", a + i);
	scanf("%d%d", &m,&y);
	for (i = 0; i < m; i++)scanf("%d", b + i);
	int ans = 0;
	for (i = 1; i < 1 << 30; i<<=1) {
		for (j = 0; j < n; j++)t[a[j]%(2*i)]++;
		for (j = 0; j < m; j++)t[(b[j] + i) % (2 * i)]++;
		for (pair<int, int> p : t)ans = max(ans, p.second);
		t.clear();
	}
	for (j = 0; j < n; j++)t[a[j] ]++;
	for (j = 0; j < m; j++)t[b[j]]++;
	for (pair<int, int> p : t)ans = max(ans, p.second);
	printf("%d", ans);
	getchar(); getchar();
}