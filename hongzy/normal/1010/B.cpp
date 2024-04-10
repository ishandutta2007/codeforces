#include <algorithm>
#include <cstdio>
using namespace std;

int m, n, a[31];

int main() {
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i ++) {
		puts("1"); fflush(stdout);
		scanf("%d", &a[i]);
		if(a[i] == 0) {
			puts("1");
			fflush(stdout);
			return 0;
		}
		a[i] = a[i] == -1 ? 0 : 1;
	}
	int l = 1, r = m, mid, x;
	for(int i = 0; l <= r; i ++) {
		mid = (l + r) >> 1;
		printf("%d\n", mid);
		fflush(stdout);
		scanf("%d", &x);
		if(!a[i % n]) x = -x;
		if(x == 0) {
			printf("%d\n", mid);
			fflush(stdout);
			break ;
		}
		if(x == -1) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}