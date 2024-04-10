#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	if(a[n] >= a[n - 1] + a[n - 2]) puts("NO");
	else {
		puts("YES");
		swap(a[n], a[n - 1]);
		for(int i = 1; i <= n; i ++) {
			printf("%d ", a[i]);
		}
	}
	return 0;
}