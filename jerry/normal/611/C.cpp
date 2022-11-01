#include <bits/stdc++.h>
using namespace std;

int h[502][502], v[502][502];
char s[502][502];
int r, c;

int getval(int arr[502][502], int a, int b)
{
	if (a<0 || b<0) return 0;
	return arr[a][b];
}

int qu(int arr[502][502], int r1, int c1, int r2, int c2)
{
	r1--, c1--;
	return getval(arr, r2, c2)-getval(arr, r1, c2)-getval(arr, r2, c1)+getval(arr, r1, c1);
}

int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0;i < r;i++) scanf("%s", s[i]);
	for (int i = 0;i < r;i++) for (int j = 0;j < c-1;j++) if (s[i][j] == '.' && s[i][j+1] == '.') h[i][j]++;
	for (int i = 0;i < r-1;i++) for (int j = 0;j < c;j++) if (s[i][j] == '.' && s[i+1][j] == '.') v[i][j]++;
	for (int i = 0;i < r;i++) for (int j = 0;j < c-1;j++) h[i][j] += getval(h, i-1, j)+getval(h, i, j-1)-getval(h, i-1, j-1);
	for (int i = 0;i < r-1;i++) for (int j = 0;j < c;j++) v[i][j] += getval(v, i-1, j)+getval(v, i, j-1)-getval(v, i-1, j-1);
	int q; scanf("%d", &q);
	while (q--)
	{
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--, c1--, r2--, c2--;
		int ans = qu(v, r1, c1, r2-1, c2)+qu(h, r1, c1, r2, c2-1);
		printf("%d\n", ans);
	}
	return 0;
}