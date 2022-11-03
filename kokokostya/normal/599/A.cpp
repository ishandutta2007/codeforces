#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = min(2 * a + 2 * b, a + b + c);
	ans = min(ans, 2 * a + 2 * c);
	ans = min(ans, 2 * b + 2 * c);
	cout << ans;
	return 0;
}