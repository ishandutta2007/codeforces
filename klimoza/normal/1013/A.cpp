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
	int sum_1 = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		sum_1 += t;
	}
	int sum_2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		sum_2 += t;
	}
	if (sum_1 >= sum_2) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	//system("pause");
	return 0;
}