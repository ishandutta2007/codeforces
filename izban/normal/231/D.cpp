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

using namespace std;

#define ll long long


const int maxn = 1 << 17;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	int x, y, z, X, Y, Z, a[6];

	cin >> x >> y >> z;
	cin >> X >> Y >> Z;
	for (int i = 0; i < 6; i++)
		cin >> a[i];

	int ans = 0;
	if (y < 0)
		ans += a[0];
	if (y > Y)
		ans += a[1];
	if (z < 0)
		ans += a[2];
	if (z > Z)
		ans += a[3];
	if (x < 0)
		ans += a[4];
	if (x > X)
		ans += a[5];

	cout << ans;

	return 0;
}