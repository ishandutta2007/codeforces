#include <bits/stdc++.h>
using namespace std;

int a[100005], x, y, t, n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", a+i), t += a[i];
	x = t/n, y = n-t%n; sort(a, a+n); t = 0;
	for (int i = 0;i < y;i++) t += abs(a[i]-x); x++;
	for (int i = y;i < n;i++) t += abs(a[i]-x);
	printf("%d\n", t>>1);
	return 0;
}