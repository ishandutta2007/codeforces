#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 567890;

int n, k;
char a[maxN], b[maxN];
int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", a);
	scanf("%s", b);
	i64 num = 0, answer = 0;
	for (int i = 0; i < n; i++) {
		num = num * 2 + ((int)b[i] - (int)a[i]);
		num = min(num, 1ll << 50);
		answer += min(num + 1, (i64)k);
	}
	printf("%lld\n", answer);
}