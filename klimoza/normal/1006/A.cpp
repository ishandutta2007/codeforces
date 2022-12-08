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
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t % 2 == 0) {
			cout << t - 1 << " ";
		}
		else {
			cout << t << " ";
		}
	}
	//system("pause");
	return 0;
}