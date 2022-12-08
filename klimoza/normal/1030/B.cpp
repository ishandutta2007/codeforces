#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>

using namespace std;


int main() {
	int n, d;
	cin >> n >> d;
	int m;
	cin >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (y <= x + d && y >= x - d && y >= -x + d && y <= -x + 2 * n - d) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	//system("pause");
	return 0;
}