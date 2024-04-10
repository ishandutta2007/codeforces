#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k[10000];
int main() {
	int n,i,a,b;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b), k[a]++, k[b]++;
	int ans = 0;
	for (i = 1; i <= n; i++)if (k[i] == 1)ans++;
	printf("%d", ans);
	getchar(); getchar();
}