#include <bits/stdc++.h>
using namespace std;

bool calc(int x) {
	int res = 0;
	for (; x; x /= 10) {
		res += x % 10;
	}
	return res % 4 == 0;
}

int main() {
	int x;
	scanf("%d", &x);
	int res = 0;
	for (int i = x; ; i++) {
		if (calc(i)) {
			res = i; break;
		}
	}
	printf("%d", res);
  return 0;
}