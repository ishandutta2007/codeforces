#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llong;

int n, k;
int arr, sum, give;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr;
		sum += arr;
		int tmp = min(8, sum);
		sum -= tmp;
		give += tmp;
		if (give >= k) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}