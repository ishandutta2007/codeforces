#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	int q;
	cin >> q;
	long long int x, y, k, f, ans;
	for (int i = 0; i < q; i++) {
		ans = 0;
		cin >> x >> y >> k;
		if (x == y) {
			ans += x;
			k -= x;
			if (k < 0) {
				cout << "-1\n";
				continue;
			}
			if (k % 2 == 1) {
				ans--;
				k--;
			}
			ans += k;
			cout << ans << "\n";
			continue;
		}
		f = min(x, y);
		ans += f;
		//cout << ans << " 1 " << k << " --- " << f << "\n";
		k -= f;
		x -= f;
		y -= f;
		if (k < 0) {
			cout << "-1\n";
			continue;
		} 
		f = max(x, y);
		if (k < f) {
			cout << "-1\n";
			continue;
		}
		ans += (f / 2) * 2;
		//cout << ans << " 2 " << k << " --- " << f << "\n";
		k -= (f / 2) * 2;
		if (f % 2 == 1) {
			if (k % 2 == 1) {
				k--;
			}
			else {
				k -= 2;
				ans++;
			}
		}
		if (k % 2 == 1) {
			ans--;
			k--;
		}
		ans += k;
		//cout << ans << " 3 " << k << " --- " << f << "\n";
		/*if (k <= 2 * f) {
			k -= f;
			ans += 2 * k;
		}
		else {
			ans += 2 * f;
			k -= 2 * f;
			if (k % 2 == 1) {
				ans--;
				k++;
			}
			ans += k / 2;
		}*/
		cout << ans << "\n";
	}
	//system("pause");
	return 0;
}