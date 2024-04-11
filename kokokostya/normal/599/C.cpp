#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;
int n;
vector<char> used;

int bp(int l, int k) {
	int m;
	int r = n - 1;
	while (l<r) {
		m = (l + r) / 2;
		if (ans[m]<k) l = m + 1;
		else r = m;
	}
	while (used[r]) { r++; }
	if (ans[r] == k) {
		used[r] = 1; return r;
	}
}

int main() {
	cin >> n;
	vector<int> arr(n);
	ans.resize(n);
	used.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans[i] = arr[i];
	}
	sort(ans.begin(), ans.end());
	int j = 0;
	int l = 0;
	int s = 0;
	int res = 0;
	while (j < n) {
		if (arr[j] == ans[l]) {
			l++;
			j++;
			s++;
			res++;
		}
		else {
			s = bp(l, arr[j]);
			while (j != s) {
				j++;
				int q = bp(l, arr[j]);
				if (q > s) { s = q; }
			}
			res++;
			j++;
			l = j;

		}

	}

	cout << res;

	return 0;
}