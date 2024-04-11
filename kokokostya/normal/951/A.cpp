#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <random>

using namespace std;

typedef long long ll;

const int md = 1e9 + 7;
mt19937 gen;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifdef LOCAl
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAl

	string s;
	cin >> s;

	s += s;

	int ans = 0;

	int n = s.length() / 2;
	int cur = 0;
	for (int i = 1; i < 2 * n; i++) {
		if (s[i] != s[i - 1]) {
			cur++;
		}
		else {
			cur = 0;
		}
		ans = max(ans, min(n, cur + 1));
	}

	cout << ans << '\n';

	return 0;
}