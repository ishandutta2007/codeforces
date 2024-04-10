#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	double ans = 1;
	int s=0,r,n,m,h,i,x;
	scanf("%d%d%d", &n, &m, &h);
	for (i = 0; i < m; i++) {
		scanf("%d", &x);
		s += x;
		if (i == h - 1)r = x;
	}
	r--, s--,n--;
	if (n > s) { printf("-1"); return 0; }
	for (i = 0; i < n; i++) {
		ans *= s - r - i, ans /= s - i;
	}
	printf("%lf", 1-ans);
	getchar(); getchar();
}