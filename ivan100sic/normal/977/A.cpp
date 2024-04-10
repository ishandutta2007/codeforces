#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, k;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	while (k--) {
		if (n % 10 == 0) {
			n /= 10;
		}
		else {
			n--;
		}
	}
	cout << n << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}