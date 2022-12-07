#include <cstdio>
#include <cstring>

const int N = 1005;

int n, num[N];

int solve() {
	int ans = 0;
	int s = 0, e = n - 1;
	while (num[s] == 0 && s < n) s++;
	while (num[e] == 0 && e >= 0) e--;
	for (int i = s ; i <= e; i++) {
		if (num[i] == num[i - 1] && num[i] == 0)
			continue;
		ans++;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	printf("%d\n", solve());
	return 0;
}