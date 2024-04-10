#include <bits/stdc++.h>
using namespace std;
int num[400000];
map<int,int> idk, val;
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", num + i);
	int ans = -1,end=-1;
	for (i = 1; i <= n; i++) {
		if (idk[num[i]] < idk[num[i] - 1] + 1) {
			idk[num[i]] = idk[num[i] - 1] + 1;
			val[num[i]] = i;
			if (idk[num[i]] > ans) {
				ans = idk[num[i]];
				end = num[i];
			}
		}
	}
	printf("%d\n", ans);
	int look = end - ans + 1;
	for (i = 1; i <= n; i++) {
		if (num[i] == look) {
			look++; printf("%d ", i);
		}
	}
}