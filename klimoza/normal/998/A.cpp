#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int ind = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < a[ind]) {
			ind = i;
		}
	}
	if (n == 1 or (n == 2 and a[0] == a[1])) {
		cout << -1 << "\n";
	}
	else {
		cout << 1 << "\n";
		cout << ind + 1<< "\n";
	}
	//system("pause");
	return 0;
}