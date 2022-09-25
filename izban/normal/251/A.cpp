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


int n, d, a[maxn];
long long ans = 0;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < n - 1 && a[j + 1] - a[i] <= d)
			j++;
		ans += max(0LL, 1LL * (j - i) * (j - i - 1) / 2);
	}

	cout << ans;

	return 0;
}