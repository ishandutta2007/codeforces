
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>
#include <deque>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;

//inline void operator delete (void *) {};

typedef long long ll;

const int MAX_N = 1e5 + 10;

int n;
long long a[MAX_N], pref[MAX_N], suf[MAX_N], b[MAX_N], c[MAX_N];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	b[0] = a[0];
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + max(0ll, b[i] - a[i]);
		b[i + 1] = max(a[i + 1], b[i] + 1);
	}
	c[n - 1] = a[n - 1];
	for (int i = 1; i <= n; i++) {
		suf[i] = suf[i - 1] + max(0ll, c[n - i] - a[n - i]);
		c[n - i - 1] = max(a[n - i - 1], c[n - i] + 1);
	}
	long long ans = 1e18;
	for (int i = 0; i < n; i++) {
		ans = min(ans, pref[i] + suf[n - i - 1] + max(b[i], c[i]) - a[i]);
	}
	cout << ans << "\n";
	return 0;
}