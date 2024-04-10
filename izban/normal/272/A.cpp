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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n) {
		int sum = 0;
		for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
		int ans = 0;
		for (int x = 1; x <= 5; x++) {
			ans += ((sum + x - 1) % (n + 1) > 0);
		}
		cout << ans << endl;
	}

	return 0;
}