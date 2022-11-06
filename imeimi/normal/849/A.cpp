#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llong;

int n;
int arr[200];
bool can[200][200];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> arr[i];
	if (arr[0] % 2 == 0) {
		printf("No\n");
		return 0;
	}
	can[0][0] = true;
	for (i = 0; i < n; ++i) {
		if (arr[i] % 2 == 0) continue;
		for (j = 0; j <= i; ++j) {
			if (!can[i][j]) continue;
			for (k = i; k < n; k += 2) {
				if (arr[k] % 2 == 0) continue;
				can[k + 1][j + 1] = true;
			}
		}
	}
	for (i = 1; i <= n; i += 2) {
		if (can[n][i]) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}