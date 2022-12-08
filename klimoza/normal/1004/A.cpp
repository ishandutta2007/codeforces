#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n, d;
	cin >> n >> d;
	int last;
	cin >> last;
	int t;
	int ans = 2;
	for (int i = 1; i < n; i++) {
		cin >> t;
		if (t - last == 2 * d) {
			ans += 1;
		}
		else if (t - last > 2 * d) {
			ans += 2;
		}
		last = t;
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}