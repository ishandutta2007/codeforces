/* 2020. 02. 17. IZ*ONE - Fiesta */

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, d, w[110], U[10100], cnt;
int i;
void Solve() {
	cnt = 0;
	scanf("%d%d", &n, &d);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		for (int j = 0; j < w[i]; j++)U[++cnt] = i - 1;
	}

	int S = 0, res = 0;
	for (i = 1; i <= cnt; i++) {
		S += U[i];
		if (S > d)break;
		res++;
	}
	printf("%d\n", res);
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}