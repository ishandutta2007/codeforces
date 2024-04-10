#include <algorithm>
#include <cstdio>
using namespace std;

void work(int prod, int n) {
	if(n == 1) {
		printf("%d ", prod);
		return ;
	}
	if(n == 3) {
		printf("%d %d %d ", prod, prod, prod * 3);
		return ;
	}
	for(int i = 1; i <= n; i += 2)
		printf("%d ", prod);
	work(prod << 1, n >> 1);
}

int main() {
	int n; scanf("%d", &n); work(1, n);
	return 0;
}