#include <bits/stdc++.h>
using namespace std;
int aa[200];
int main() {
	int n, i,j,ans=0;
	scanf("%d", &n);
	for (i = 0; i < 2 * n; i++)scanf("%d", aa + i);
	for (i = 0; i < 2 * n; i+=2) {
		int l = aa[i];
		for (j = 2 * n - 1; j-1 > i; j--) {
			if (aa[j] == l)ans++, aa[j - 1] ^= aa[j] ^= aa[j - 1] ^= aa[j];
		}
	}
	printf("%d", ans);
	getchar(); getchar();
}