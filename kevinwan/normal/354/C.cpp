#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
int s=0x3f3f3f3f, a[2000001];
int main() {
	int n, k, x, i,j;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)scanf("%d", &x), a[x]++, s = min(s, x);
	for (i = 1; i <= 2000000; i++)a[i] += a[i - 1];
	for (i = s; i; i--) {
		if (i <= k + 1) { printf("%d", i); getchar(); getchar(); return 0; }
		int nok = 0;
		for (j = 0; j*i <= 1000000; j++)nok |= a[j*i + i - 1] - a[j*i + k];
		if(!nok) { printf("%d", i); getchar(); getchar(); return 0; }
	}
	getchar(); getchar();
}