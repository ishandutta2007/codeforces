#include <bits/stdc++.h>
using namespace std;

int n, k, p, a[1005], b[2005];
int ans[1005][2005];
bool vi[1005][2005];

int slv(int i, int j)
{
	if (i == n) return 0;
	if (j == k) return 2147483647;
	if (vi[i][j]) return ans[i][j];
	vi[i][j] = true;
	return ans[i][j] = min(slv(i, j+1), max(slv(i+1, j+1), abs(a[i]-b[j])+abs(b[j]-p)));
}

int main()
{
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 0;i < n;i++) scanf("%d", a+i);
	for (int j = 0;j < k;j++) scanf("%d", b+j);
	sort(a, a+n); sort(b, b+k);
	printf("%d\n", slv(0, 0));
	return 0;
}