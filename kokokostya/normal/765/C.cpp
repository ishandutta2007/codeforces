#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

int main() {
	int k, a, b;
	cin >> k >> a >> b;
	int res1 = a / k;
	int res2 = b / k;
	if (a % k && !res2) {
		cout << -1;
		return 0;
	}
	if (b % k && !res1) {
		cout << -1;
		return 0;
	}
	cout << res1 + res2;
	return 0;
}