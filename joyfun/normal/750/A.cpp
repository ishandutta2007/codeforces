#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	int s = 5;
	for (int i = 0; i < n; i++) {
		k += s;
		if (k > 240) {
			printf("%d\n", i);
			return 0;
		}
		s += 5;
	}
	printf("%d\n", n);
	return 0;
}