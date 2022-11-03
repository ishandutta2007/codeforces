#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	int k = 1;
	int ansk = 0;
	int r = 0;
	int ansr = 0;
	bool is = 0;
	bool is2 = 0;
	bool is1 = 0;
	vector <int> arr(n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		int l = c - '0';
		arr[i] = l;
		if (l == k) { ansk++; k = (k + 1) % 2; }
		if (l == r) { ansr++; r = (r + 1) % 2; }
		if (i > 0 && is2 == 1) { if (arr[i] == arr[i - 1]) { is1 = 1; } }
		if (i > 0) { if (arr[i] == arr[i - 1]) { is2 = 1; } }
		
	}
	int ans = max(ansk, ansr);
	if (is2) { ans++; }
	if (is1) { ans++; }
	cout << ans;

	return 0;
}