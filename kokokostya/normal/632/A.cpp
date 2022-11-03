#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "half") { arr[i] = 1; }
	}
	long long res = 0;
	long long j = 0;
	for (int i = n - 1; i >= 0; i--) {
		res *= 2;
		if (arr[i] == 0) { res++; j++; }
	}
	cout << res * p - (p / 2) * j;
	return 0;
}