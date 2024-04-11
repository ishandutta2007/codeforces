#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector< pair< int, int> > arr(n);
	vector< pair< int, int> > b(m);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(arr.begin(), arr.end());
	sort(b.begin(), b.end());
	bool amb = 0;
	bool is = 1;
	int i = 0;
	int j = 0;
	vector<int> ans(m);
	while (j < m && is) {
		while (i < n) {
			if (b[j].first == arr[i].first) { break; }
			i++;
		}
		if (i != n - 1 && i != n) { if (b[j].first == arr[i + 1].first) { amb = 1; } }
		if (i != n) { ans[b[j].second] = arr[i].second; }
		else { is = 0; }
		j++;
	}
	if (is == 0) { cout << "Impossible"; return 0; }
	if (amb == 1) { cout << "Ambiguity"; return 0; }
	cout << "Possible" << '\n';
	for (int i = 0; i < m; i++) {
		cout << ans[i] + 1 << ' ';
	}

	return 0;
}