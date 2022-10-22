#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n, K;
char p[101000];
int S[101000];
int main() {
	int i;
	scanf("%d%d", &n, &K);
	scanf("%s", p + 1);
	for (i = 1; i <= n; i++) {
		S[i] = S[i - 1] + p[i] - '0';
	}
	for (i = 0; i <= n-K; i++) {
		int z = S[n] - (S[i + K] - S[i]);
		if (z == 0 || z == n - K) {
			puts("tokitsukaze");
			return 0;
		}
	}
	for (i = 0; i <= n - K; i++) {
		int a = S[i], b = S[n] - S[i + K];

		if (a && b) {
			puts("once again");
			return 0;
		}
		if (i - a && n - (i + K) - b) {
			puts("once again");
			return 0;
		}
	}
	if (n > 2 * K) {
		puts("once again");
	}
	else puts("quailty");
}