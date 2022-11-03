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
#include<cmath>

using namespace std;
//#define LOCAL

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s, t;
	cin >> s >> t;
	int n = (int)s.length();
	vector<char> ans(n);
	vector<char> a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = s[i];
		b[i] = t[i];
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	int l1 = 0, r1 = ((n + 1) / 2) - 1, l2 = 0, r2 = (n / 2) - 1;
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++) {
		if (i % 2) {
			if (a[l1] >= b[l2]) {
				ans[r] = b[r2];
				r2--;
				r--;
			}
			else {
				ans[l] = b[l2];
				l2++;
				l++;
			}
		}
		else {
			if (a[l1] >= b[l2]) {
				ans[r] = a[r1];
				r1--;
				r--;
			}
			else {
				ans[l] = a[l1];
				l1++;
				l++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
	return 0;
}