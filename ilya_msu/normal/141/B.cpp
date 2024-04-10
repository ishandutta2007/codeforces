#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;



int main() {
	int a, x, y;
	cin >> a >> x >> y;
	if (y % a == 0) {
		cout << -1 << endl;
		return 0;
	}
	if (y < a) {
		if ((2 * x < a) && (2 * x > -a))
			cout << 1 << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	y = y - a;
	int q = y / (2 * a);
	y = y - q * 2 * a;
	int add = 3 * q + 1;
	if (y < a) {
		if ((2 * x < a) && (2 * x > -a))
			cout << 1 + add << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	if ((x > 0) && (x < a)) {
		cout << add + 3 << endl;
		return 0;
	}
	if ((x < 0) && (x > -a)) {
		cout << add + 2 << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}