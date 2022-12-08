#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	int n;
	cin >> n;
	int t;
	vector<int> a(2 * 1e5 + 1, -1);
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[t] = i;
	}
	int min_i = 0;
	int mini = 1e9;
	for (int i = 0; i < 2 * 1e5 + 1; i++) {
		if (a[i] != -1 && mini > a[i]) {
			min_i = i;
			mini = a[i];
		}
	}
	cout << min_i << "\n";
	//system("pause");
	return 0;
}