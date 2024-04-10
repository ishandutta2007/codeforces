#include<cstdio>
#include<algorithm>
using namespace std;
long long L, K, w[101000], res;
int n;
int main() {
	scanf("%lld%d%lld", &L, &n, &K);
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
	}
	int pv = 1;
	while (pv <= n) {
		long long cur = (w[pv] - pv) / K;
		int i;
		for (i = pv; i <= n; i++) {
			if (cur != (w[i] - pv) / K) break;
		}
		res++;
		pv = i;
	}
	printf("%lld\n", res);
}