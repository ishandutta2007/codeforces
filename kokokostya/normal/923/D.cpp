
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>

using namespace std;

typedef long long ll;
const ll md = 1e9 + 7;
const int MX = 1e6 + 1;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s, t;
	cin >> s >> t;

	for (char & c : s) {
		if (c == 'C') {
			c = 'B';
		}
	}
	for (char & c : t) {
		if (c == 'C') {
			c = 'B';
		}
	}

	int n = s.length(), m = t.length();

	vector<int> sb(n + 1, 0), tb(m + 1, 0), sa(n + 1, 0), ta(m + 1, 0);
	for (int i = 0; i < n; i++) {
		sb[i + 1] = sb[i] + (s[i] == 'B');
		sa[i + 1] = (s[i] == 'A' ? sa[i] + 1 : 0);
	}
	for (int i = 0; i < m; i++) {
		tb[i + 1] = tb[i] + (t[i] == 'B');
		ta[i + 1] = (t[i] == 'A' ? ta[i] + 1 : 0);
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int b1 = sb[b] - sb[a - 1], b2 = tb[d] - tb[c - 1];
		int l1 = min(sa[b], b - a + 1), l2 = min(ta[d], d - c + 1);
		bool ch = (b1 <= b2) && ((b2 - b1) % 2 == 0);
		if (l1 < b - a + 1) {
			ch &= (l1 >= l2);
			if (b1 == b2) {
				ch &= ((l1 - l2) % 3 == 0);
			}
		} else {
			if (l2 == d - c + 1) {
				ch &= (l1 >= l2);
				if (b1 == b2) {
					ch &= ((l1 - l2) % 3 == 0);
				}
			} else {
				ch &= (l1 > l2);
				if (b1 == b2) {
					ch &= ((l1 - l2) % 3 == 0);
				}
			}
		}
		cout << ch;
	}

    return 0;
}