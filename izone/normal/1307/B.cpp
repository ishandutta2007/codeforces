/* 2020. 02. 17. IZ*ONE - Fiesta */

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long L, w[101000];
void Solve() {
	int i;
	scanf("%d%lld", &n, &L);
	int ck = 0;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		if (w[i] == L)ck = 1;
	}
	sort(w + 1, w + n + 1);
	long long res = (L + w[n] - 1) / w[n];
	if (res == 1 && !ck)res++;
	printf("%lld\n", res);
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}