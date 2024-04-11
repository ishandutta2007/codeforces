#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int i = 0;
	int j = 0;
	vector<int> ans;
	if (arr[0] <= s) { cout << "IMPOSSIBLE"; return 0; }
	while (i!= m) {
		if (j == n) { ans.push_back(m - i); i = m; }
		else {
			ans.push_back(arr[j] - i - 1);
			i = arr[j] - 1;
			int u = i;
			bool is = 1;
			int k = d;
			while (is) {
				j++;
				if (j == n) { is = 0; }
				if (j!= n &&(arr[j] - arr[j - 1] - 2 >= s)) { is = 0; }
				k -= (arr[j - 1] + 1 - i);
				i = arr[j - 1] + 1;
			}
			if (k < 0) { cout << "IMPOSSIBLE"; return 0; }
			else { ans.push_back(i - u); }
		}
	}
	for (int q = 0; q < ans.size(); q++) {
		if (q % 2 == 0) { cout << "RUN"; }
		else { cout << "JUMP"; }
		cout << ' ' << ans[q] << '\n';
	}

	return 0;
}