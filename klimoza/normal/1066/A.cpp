#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int t, L, v, l, r;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> L >> v >> l >> r;
		cout << L / v - r / v + (l - 1) / v << "\n";
	}
	//system("pause");
	return 0;
}