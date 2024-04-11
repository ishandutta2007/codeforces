#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>

using namespace std;
//#define LOCAL

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, a, b, c;
	cin >> a >> b >> c >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		if (val > b && val < c)
			ans++;
	}
	cout << ans;
	return 0;
}