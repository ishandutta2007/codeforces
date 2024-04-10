#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn];
int sum[maxn];
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) sum[i] = (i ? sum[i - 1] : 0) + a[i];
		cin >> s;

		int cur = 0, ans = -1;
		for (int i = (int)s.length() - 1; i >= 0; i--) {
			if (s[i] == '1') {
				ans = max(ans, cur + (i ? sum[i - 1] : 0));
				cur += a[i];
			}
		}
		ans = max(ans, cur);
		cout << ans << endl;
	}

	return 0;
}