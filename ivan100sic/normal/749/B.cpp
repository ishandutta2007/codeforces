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

	int x1, y1, x2, y2, x3, y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	cout << "3\n";

	cout << (x1 + x2 - x3) << ' ' << (y1 + y2 - y3) << '\n';
	cout << (x2 + x3 - x1) << ' ' << (y2 + y3 - y1) << '\n';
	cout << (x3 + x1 - x2) << ' ' << (y3 + y1 - y2) << '\n';

}