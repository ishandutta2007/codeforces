#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n, w;
	cin >> n >> w;
	int maxi = 0;
	int mini = 0;
	int cur = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		cur += t;
		maxi = max(maxi, cur);
		mini = min(mini, cur);
	}
	int r = w - maxi;
	int l = max(0, -mini);
	if (r < l) {
		cout << 0 << "\n";
	}
	else {
		cout << r - l + 1 << "\n";
	}
	//system("pause");
	return 0;
}