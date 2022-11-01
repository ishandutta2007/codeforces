#include <bits/stdc++.h>
using namespace std;

char a[100005], b[100005];
long long occ[2][2], ans;
int n;

int main()
{
	scanf("%d%s%s", &n, a, b);
	for (int i = 0;i < n;i++) occ[a[i]-'0'][b[i]-'0']++;
	for (int i = 0;i < 2;i++) for (int j = 0;j < 2;j++) for (int k = 0;k < 2;k++) for (int l = 0;l < 2;l++) if (i*2+j != k*2+l && ((i|j) != (k|j) || (k|l) != (i|l))) ans += occ[i][j]*occ[k][l];
	printf("%lld\n", ans/2);
	return 0;
}