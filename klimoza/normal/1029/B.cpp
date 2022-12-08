#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cur;
	cin >> cur;
	int maxi = 1;
	int count = 1;
	int t;
	for (int i = 1; i < n; i++) {
		cin >> t;
		if (t <= 2 * cur) {
			count++;
		}
		else {
			maxi = max(maxi, count);
			count = 1;
		}
		cur = t;
	}
	maxi = max(maxi, count);
	cout << maxi << "\n";
	//system("pause");
	return 0;
}