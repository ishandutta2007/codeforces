#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> s;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') { res += arr[i]; }
	}
	long long x = 0;
	long long mx = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') { x -= arr[i]; }
		else { x += arr[i]; }
		if (x > mx) { mx = x; }
	}
	long long h = mx;
	x = 0;
	mx = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'B') { x -= arr[i]; }
		else { x += arr[i]; }
		if (x > mx) { mx = x; }
	}
	if (mx >= h && mx > 0) {
		cout << res + mx;
	}
	if (h > mx && h > 0) {
		cout << res + h;
	}
	if (h <= 0 && mx <= 0) {
		cout << res;
	}

	return 0;
}