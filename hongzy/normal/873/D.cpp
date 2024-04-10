#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int n, k, cnt, a[N];
void merge(int l, int r) {
	if(cnt == k || l + 1 == r) {
		for(int i = l; i < r; i ++) a[i] = i - l + 1;
		return ;
	}
	int mid = (l + r) >> 1;
	cnt += 2;
	merge(l, mid);
	for(int i = l; i < mid; i ++) a[i] += r - mid;
	merge(mid, r);
}
int main() {
	scanf("%d%d", &n, &k);
	if(k % 2 == 0) return puts("-1"), 0;
	cnt = 1; merge(0, n);
	if(cnt != k) puts("-1");
	else {
		for(int i = 0; i < n; i ++)
			printf("%d ", a[i]);
	}
	return 0;
}