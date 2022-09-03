#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char a[1001], b[1001];

int main() {
	int i, j, n, t;
	scanf("%d%s%s", &n, a, b);
	sort(a, a + n);
	sort(b, b + n);
	for (i = j = t = 0; j < n; j++) {
		if (a[i] > b[j]) t++;
		else i++;
	}
	printf("%d\n", t);
	for (i = j = t = 0; i < n; i++) {
		while (j < n && a[i] >= b[j]) j++;
		if (j < n) {
			t++;
			j++;
		}
	}
	printf("%d\n", t);
}