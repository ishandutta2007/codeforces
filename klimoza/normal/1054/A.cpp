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
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int ans1 = abs(x - y) * t1;
	int ans2 = (abs(x - z) + abs(x - y)) * t2 + 3 * t3;
	if(ans1 < ans2) {
		cout << "NO\n";
	}
	else {
	 cout << "YES\n";
	}
	//system("pause");
	return 0;
}