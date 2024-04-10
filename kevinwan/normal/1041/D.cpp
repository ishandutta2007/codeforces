#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int l[200001], r[200001],up[200001],t[200001],reach[200001];
int main() {
	int n, h,i,ch;
	scanf("%d%d", &n, &h);
	for (i = 1; i <= n; i++)scanf("%d%d", l + i, r + i),t[i]=r[i]-l[i];
	for (i = 1; i <= n; i++)t[i] += t[i - 1];
	int cur = 0;
	ch = h;
	for (i = 1; i <= n; i++) {
		up[i] = up[i - 1] + l[i] - r[i - 1];
		ch -= l[i] - r[i - 1];
		while (ch + up[cur] <= 0)reach[cur] = i - 1, cur++;
	}
	for (i = cur; i <= n; i++)reach[i] = n;
	int ans=0;
	for (i = 1; i <= n; i++) {
		ans = max(ans, t[reach[i]] - t[i-1]);
	}
	printf("%d", ans + h);
	getchar(); getchar();
}