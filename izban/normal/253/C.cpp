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

int n, a[maxn], r1, c1, r2, c2;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> r1 >> c1 >> r2 >> c2;
	r1--; r2--;

	int ans = inf;
	for (int x = 0; x < n; x++) {
		int cans = 0;
		int cur = c1;
		for (int i = r1; i != x; i += (r1 < x) - (r1 > x)) 
			cur = min(cur, a[i] + 1);
		for (int i = x; i != r2; i += (x < r2) - (x > r2)) 
			cur = min(cur, a[i] + 1);
		cur = min(cur, a[r2] + 1);
		cans = abs(x - r1) + abs(x - r2) + abs(c2 - cur);
		ans = min(ans, cans);
	}
	cout << ans;

	return 0;
}