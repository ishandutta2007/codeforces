#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a;
	cin >> a;
	int b = a;
	long long ans = abs(a);
	for (int i = 1; i < n; i++) {
		cin >> a;
		ans += abs(a - b);
		b = a;
	}
	cout << ans;

	return 0;
}