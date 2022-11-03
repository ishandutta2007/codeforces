#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(100005);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a]++;
	}
	for (int i = 1; i < 100005; i++)
		arr[i] += arr[i - 1];
	int q;
	cin >> q;
	while (q--) {
		int m;
		cin >> m;
		if (m > 100003)
			cout << n << '\n';
		else
			cout << arr[m] << '\n';
	}
	return 0;
}