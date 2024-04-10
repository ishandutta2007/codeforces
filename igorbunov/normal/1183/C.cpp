#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define int long long

signed main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int k, n, a, b;
		cin >> k >> n >> a >> b;
		if (b * n >= k) {
			cout << -1 << "\n";
			continue;
		}
		if (a * n < k) {
			cout << n << endl;
			continue;
		}
		int l = 0;
		int r = n;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (m * a + (n - m) * b < k) {
				l = m;
			} else {
				r = m;
			}
		}
		cout << l << endl;
	}
}