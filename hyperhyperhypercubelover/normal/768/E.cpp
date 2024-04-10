#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int a[61] = { 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10 };

int main() {
	int i, n, r = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &i);
		r ^= a[i];
	}
	puts(r ? "NO" : "YES");
}