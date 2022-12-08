#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') {
			cur++;
		}
		else {
			cur = 0;
		}
		if (cur > 2) {
			ans += 1;
		}
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}