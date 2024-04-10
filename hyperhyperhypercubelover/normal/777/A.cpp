#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	n %= 6;
	while (n--) {
		if (n & 1) {
			if (x != 0) x = 3 - x;
		}
		else {
			if (x != 2) x = 1 - x;
		}
	}
	printf("%d", x);
}