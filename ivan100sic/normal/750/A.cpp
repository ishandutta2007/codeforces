#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k, t = 0;

	cin >> n >> k;

	for (int i=1; i<=n; i++) {
		if (t + 5*i + k > 240) {
			cout << i-1;
			return 0;
		} else {
			t += 5*i;
		}
	}
	cout << n;
}