#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, num[1005];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int ans1 = 0, ans2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	int l = 0, r = n - 1, j = 0;
	while (l <= r) {
		if (num[l] > num[r]) {
			if (j % 2 == 0)
				ans1 += num[l++];
			else
				ans2 += num[l++];
		}
		else {
			if (j % 2 == 0)
				ans1 += num[r--];
			else
				ans2 += num[r--];
		}
		j++;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}