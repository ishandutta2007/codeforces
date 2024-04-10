#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[150000],a[150000];
int main() {
	int n,i,st,am=0;
	ll num;
	scanf("%d", &n);
	st = 0;
	for (i = 0; i < n; i++)scanf("%lld", b + i);
	num = b[0];
	for (i = 0; i < n; i++)if (b[i] == num)am++;
	if (am == n&&num!=0) { printf("NO"); return 0; }
	if (am == n && num == 0) { printf("YES\n"); for (i = 0; i < n; i++)printf("1 "); getchar(); getchar(); return 0; }
	for (i = 0; i < n;i++)if (b[i%n] > b[st%n])st = i;
	while (b[(st + n - 1) % n] == b[st])st = (st + n - 1) % n;
	a[st] = b[st];
	for (i = n + st - 1; i > st; i--) {
		a[i%n] = a[(i + 1) % n] + b[i%n];
		if (b[i%n] == 0 && a[i%n] == a[st])a[i%n] *= 2;
	}
	printf("YES\n");
	for (i = 0; i < n; i++)printf("%lld ", a[i]);
	getchar(); getchar();
}