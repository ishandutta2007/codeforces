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


int n, m;
int a[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m) {
		for (int i = 0; i < m; i++) cin >> a[i];
		sort(a, a + m);
		int ans = 1e9;
		for (int i = 0; i <= m - n; i++) {
			ans = min(ans, a[i + n - 1] - a[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}