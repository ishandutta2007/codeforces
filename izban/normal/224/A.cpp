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
    
	int x, y, z;
	cin >> x >> y >> z;
	double res = sqrt(1.0*x*y/z) + sqrt(1.0*x*z/y) + sqrt(1.0*y*z/x);
	res *= 4;
	int ans = int(res + 0.01);
	cout << ans;

	return 0;
}