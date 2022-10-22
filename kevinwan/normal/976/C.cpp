#include <bits/stdc++.h>
using namespace std;
struct thing {
	int l, r, i;
};
bool f(thing a, thing b) {
	if (a.l < b.l)return 1;
	if (a.l == b.l&&a.r > b.r)return 1;
	return 0;
}
thing arr[300001];
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i] = { a,b,i };
	}
	sort(arr + 1, arr + n + 1,f);
	int hi=0;
	for (i = 1; i <= n; i++) {
		if (arr[i].r <= hi) {
			printf("%d %d", arr[i].i, arr[i-1].i);
			return 0;
		}
		else hi = arr[i].r;
	}
	printf("-1 -1");
}