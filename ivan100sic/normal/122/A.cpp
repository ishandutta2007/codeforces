#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<int> a = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

	int n;
	cin >> n;
	for (int x : a) {
		if (n % x == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}