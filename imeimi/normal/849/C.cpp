#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llong;

int n;
int arr[10000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int i, j, k;
	cin >> n;
	if (n == 0) {
		printf("abcd");
		return 0;
	}

	arr[1] = 0;
	arr[2] = 1;
	for (i = 3; i < 500; ++i) {
		arr[i] = 2e9;
		for (j = 1; 2 * j <= i; ++j) {
			arr[i] = min(arr[i], arr[j] + arr[i - j] + j * (i - j));
		}
		//printf("%d %d\n", i, arr[i]);
	}
	char c = 'a';
	while (n > 0) {
		for (i = 1; arr[i] <= n; ++i);
		n -= arr[i - 1];
		while (--i) printf("%c", c);
		++c;
	}
	return 0;
}