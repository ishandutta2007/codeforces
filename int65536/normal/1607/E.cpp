#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

string solve() {
	int n;
	int m;
	cin >> n >> m;
	string s;
	cin >> s;
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int x0 = 0;
	int y0 = 0;
	int ret = 0;
	for (char c : s) {
		if (c == 'D') {
			++x0;
		} else if (c == 'U') {
			--x0;
		} else if (c == 'L') {
			--y0;
		} else {
			++y0;
		}
		int last_x1 = x1;
		int last_y1 = y1;
		x1 = min(x1, x0);
		x2 = max(x2, x0);
		y1 = min(y1, y0);
		y2 = max(y2, y0);
		if (x2 - x1 >= n || y2 - y1 >= m) {
			return to_string(-last_x1 + 1) + " " + to_string(-last_y1 + 1);
		}
		++ret;
	}
	return to_string(-x1 + 1) + " " + to_string(-y1 + 1);
}

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		cout << solve() << endl;
	}
	return 0;
}