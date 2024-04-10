#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool use[1001];
int a[1000], b[1000],ans[1001],num[1001];
int main() {
	int n,cur=0,i,j;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		scanf("%d%d", a + i, b + i);
		if (b[i] != n) {
			printf("NO"); return 0;
		}
		num[a[i]]++;
	}
	int tot = 0;
	for (i = 1; i <= n; i++) {
		tot += num[i];
		if (tot > i) { printf("NO"); return 0; }
		int sub = num[i];
		for (j = i; j &&sub; j--) {
			if (use[j])continue;
			use[j] = 1;
			sub--;
			ans[cur++] = j;
		}
	}
	printf("YES\n");
	ans[cur++] = n;
	for (i = 1; i < n; i++)printf("%d %d\n", ans[i - 1], ans[i]);
	getchar(); getchar();
}