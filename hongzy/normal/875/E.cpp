#include <algorithm>
#include <cstdio>
using namespace std;
int n, s1, s2, a[100010];
bool in(int x, int l, int r) {
	return l <= x && x <= r;
}
bool check(int mid) {
	int l = a[n] - mid, r = a[n] + mid;
	for(int i = n - 1; i >= 1; i --) {
		if(in(a[i], l, r)) {
			l = a[i] - mid; r = a[i] + mid;
		} else {
			l = max(l, a[i] - mid);
			r = min(r, a[i] + mid);
		}
	}
	return in(s1, l, r) || in(s2, l, r);
}
int main() {
	scanf("%d%d%d", &n, &s1, &s2);
	for(int i = 1; i <= n; i ++)
		scanf("%d", a + i);
	if(s1 > s2) swap(s1, s2);
	int l = s2 - s1, r = 1e9;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", r + 1);
	return 0;
}