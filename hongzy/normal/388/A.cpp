#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 110;

int n, a[N], lim[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) {
		fill(lim + 1, lim + i + 1, n * n);
		int k = 1; bool tag = 0;
		for(int j = 1; j <= n; j ++) {
			if(!lim[k]) {
				tag = 1; break ;
			}
			lim[k] = min(lim[k] - 1, a[j]);
			k = k == i ? 1 : k + 1;
		}
		if(!tag) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}