#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;

int n, a[N];
long long b[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	b[n] = a[n];
	for(int i = n - 1; i >= 1; i --) {
		b[i] = a[i] + a[i + 1];
	}
	for(int i = 1; i <= n; i ++) {
		printf("%d ", b[i]);
	}
	return 0;
}