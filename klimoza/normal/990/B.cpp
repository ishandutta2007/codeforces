#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;



int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = n;
	int cur = 1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			cur++;
		}
		else {
			if (a[i + 1] <= a[i] + k) {
				ans -= cur;
			}
			cur = 1;
		}
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}