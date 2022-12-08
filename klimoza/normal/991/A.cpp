#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	int h = n - (a + b - c);
	if (h <= 0 or c > a or c > b) {
		cout << -1 << "\n";
	}
	else {
		cout << h << "\n";
	}
	//system("pause");
	return 0;
}