#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	long long res = 0;
	int prev = -1000000001;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (t == prev) {
			++cnt;
		} else
			cnt = 1;
		res += cnt;
		prev = t;
	}
	printf("%I64d\n", res);
	return 0;
}