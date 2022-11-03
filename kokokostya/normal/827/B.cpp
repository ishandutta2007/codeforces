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
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	queue<int> q;
	int ans = 2;
	n -= k + 1;
	ans += 2 * (n / k);
	if (n % k == 1)
		ans++;
	if (n % k >= 2)
		ans += 2;
	cout << ans << '\n';
	for (int i = 0; i < k; i++) {
		cout << 1 << ' ' << i + 2 << '\n';
		q.push(i + 1);
	}
	int is = k + 1;
	
	while (n) {
		n--;
		cout << q.front() + 1 << ' ' << is + 1 << '\n';
		q.pop();
		q.push(is);
		is++;
	}


	return 0;
}