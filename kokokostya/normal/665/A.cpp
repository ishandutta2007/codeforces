#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, ta, b, tb, h, m;
	char c;
	cin >> a >> ta >> b >> tb >> h;
	cin >> c;
	cin >> m;
	int res = 0;
	int k = 60 * h + m;
	for (int i = 300; i < 1440; i++) {
		if ((i + tb > k) && (i < k + ta) && ((i - 300) % b == 0)) { res++; }
	}
	cout << res;
	return 0;
}