#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue> 

using namespace std;

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> ans(k, -1);
	for (int i = 0; i < q; i++) {
		int t, a;
		cin >> t >> a;
		if (t == 1) {
			int mn = 2000000000;
			int mn2 = -1;
			for (int i = 0; i < k; i++) {
				if (ans[i] == -1) { mn = -1; mn2 = i; }
				else {
					if (arr[ans[i]] < mn) {
						mn = arr[ans[i]];
						mn2 = i;
				} }
			}
			if ((mn2 != -1) && (ans[mn2] == -1 || arr[ans[mn2]] < arr[a - 1])) { ans[mn2] = a - 1; }
		}
		else {
			bool is = 0;
			for (int i = 0; i < k; i++) {
				if (ans[i] + 1 == a) { is = 1; }
			}
			if (is) { cout << "YES" << '\n'; }
			else { cout << "NO" << '\n'; }
		}
	}

	return 0;
}