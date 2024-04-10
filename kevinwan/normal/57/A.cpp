#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n,a,b,c,d,i,e,f;
	scanf("%d%d%d%d%d", &n,&a,&b,&c,&d);
	int cnt=0;
	for (i = 0; i <= n; i++, cnt++) {
		if (a == i && b == 0)e = cnt;
		if (c == i && d == 0)f = cnt;
	}
	for (i = 1; i <= n; i++,cnt++) {
		if (a == n && b == i)e = cnt;
		if (c == n && d == i)f = cnt;
	}
	for (i = n - 1; i >= 0; i--, cnt++) {
		if (a == i && b == n)e = cnt;
		if (c == i && d == n)f = cnt;
	}
	for (i = n - 1; i; i--, cnt++) {
		if (a == 0 && b == i)e = cnt;
		if (c == 0 && d == i)f = cnt;
	}
	printf("%d", min(abs(e- f), 4 * n - abs(e- f)));
}