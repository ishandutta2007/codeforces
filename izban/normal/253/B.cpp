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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, a[maxn];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = 100000000;
	sort(a, a + n);
	int ans = 10 * n;
	for (int i = 0; i < n; i++) {
		int r = upper_bound(a, a + n + 1, 2 * a[i]) - a;
		ans = min(ans, i + n - r);
	}
	cout << ans;
	return 0;
}