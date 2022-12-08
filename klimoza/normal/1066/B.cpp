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
	int n, r;
	cin >> n >> r;
	r--;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int cur = -1;
	int ans = 0;
	bool fl = true;
	while(cur == -1 || cur + r < n - 1) {
		int ind = cur + 1 + 2 * r;
		if (cur == -1) ind -= r;
		bool bl = true;
		for (int i = min(n - 1, ind); i > cur; i--) {
			if (a[i] == 1) {
				ans++;
				cur = i;
				bl = false;
				break;
			}
		}
		//cout << cur << " " << a[cur] << "\n";
		if (bl) {
			fl = false;
			break;
		}
	}
	if (!fl) {
		cout << "-1\n";
	}
	else {
		cout << ans << "\n";
	}
	//system("pause");
	return 0;
}