#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	int n, l, a;
	cin >> n >> l >> a;
	if (n != 0) {
		int last_t1, last_t2;
		cin >> last_t1 >> last_t2;
		int ans = last_t1 / a;
		int t1, t2;
		for (int i = 1; i < n; i++) {
			cin >> t1 >> t2;
			ans += (t1 - last_t1 - last_t2) / a;
			last_t1 = t1;
			last_t2 = t2;
		}
		ans += (l - last_t1 - last_t2) / a;
		cout << ans << "\n";
	}
	else {
		cout << l / a << "\n";
	}
	//system("pause");
	return 0;
}