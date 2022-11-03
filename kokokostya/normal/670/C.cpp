#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a]++;
	}
	int m;
	cin >> m;
	vector<int> first(m);
	vector<int> second(m);
	for (int i = 0; i < m; i++) {
		cin >> first[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> second[i];
	}
	int mx = 0;
	for (int i = 0; i < m; i++) {
		if (arr[first[i]] > mx) { mx = arr[first[i]]; }
	}
	int mx2 = 0;
	int ans;
	for (int i = 0; i < m; i++) {
		if (arr[first[i]] == mx && arr[second[i]] >= mx2) { mx2 = arr[second[i]]; ans = i; }
	}
	cout << ans + 1;
	return 0;
}