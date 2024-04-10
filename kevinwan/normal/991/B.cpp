#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
	int n,i,tar;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", a + i);
	sort(a, a + n);
	tar = (n * 9 + 1) / 2;
	int cur = 0,ans=0;
	for (i = 0; i < n; i++)cur += a[i];
	for (i = 0; i < n; i++) {
		if (cur >= tar)break;
		cur += 5 - a[i],ans++;
	}
	printf("%d", ans);
	getchar(); getchar();
}