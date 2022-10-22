#include <bits/stdc++.h>
using namespace std;
int id[256];
int main() {
	int n, k,i,j;
	scanf("%d%d", &n, &k);
	memset(id, 0x80, sizeof(id));
	for (i = 0; i < n; i++) {
		int x,ans;
		scanf("%d", &x);
		if (id[x] != 0x80808080) {
			printf("%d ", id[x]);
			continue;
		}
		for (j = x; j > x - k && j >= 0; j--) {
			if(id[j]==0x80808080)ans = j;
			if (x - id[j] < k) {
				ans = id[j];
				break;
			}
		}
		printf("%d ", ans);
		for (j = x; j >= ans; j--)id[j] = ans;
	}
}