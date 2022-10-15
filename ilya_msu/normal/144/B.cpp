#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>

using std::next_permutation;
using std::sqrt;
using std::priority_queue;
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
using std::swap;


int main() {
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2)
		swap(y1, y2);
	vector<vector<bool>> data(x2 - x1 + 1, vector<bool>(y2 - y1 + 1, false));
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y, r;
		cin >> x >> y >> r;
		for (int i = y; r * r - (x - x1) * (x - x1) >= (y - i) * (y - i); ++i) {
			if ((i - y1 >= 0) && (i - y1 < y2 - y1 + 1))
				data[0][i - y1] = true;
			if ((2 * y - i - y1 >= 0) && (2 * y - i - y1 < y2 - y1 + 1))
				data[0][y - i + y - y1] = true;
		}
		for (int i = y; r * r - (x - x2) * (x - x2) >= (y - i) * (y - i); ++i) {
			if ((i - y1 >= 0) && (i - y1 < y2 - y1 + 1))
				data[x2 - x1][i - y1] = true;
			if ((2 * y - i - y1 >= 0) && (2 * y - i - y1 < y2 - y1 + 1))
				data[x2 - x1][y - i + y - y1] = true;
		}
		for (int i = x; r * r - (y - y1) * (y - y1) >= (x - i) * (x - i); ++i) {
			if ((i - x1 >= 0) && (i - x1 < x2 - x1 + 1))
				data[i - x1][0] = true;
			if ((2 * x - i - x1 >= 0) && (2 * x - i - x1 < x2 - x1 + 1))
				data[x - i + x - x1][0] = true;
		}
		for (int i = x; r * r - (y - y2) * (y - y2) >= (x - i) * (x - i); ++i) {
			if ((i - x1 >= 0) && (i - x1 < x2 - x1 + 1))
				data[i - x1][y2 - y1] = true;
			if ((2 * x - i - x1 >= 0) && (2 * x - i - x1 < x2 - x1 + 1))
				data[x - i + x - x1][y2 - y1] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < x2 - x1 + 1; ++i) {
		if (!data[i][0])
			++ans;
		if (!data[i][y2 - y1])
			++ans;
	}
	for (int i = 1; i < y2 - y1; ++i) {
		if (!data[0][i])
			++ans;
		if (!data[x2 - x1][i])
			++ans;
	}
	cout << ans << endl;

	
	return 0;	
}