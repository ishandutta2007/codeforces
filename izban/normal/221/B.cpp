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

int n, ans;

bool check(int a, int b) {
	vector<int> c(10);
	while (a) 
		c[a%10]++, a/=10;
	while (b) 
		if (c[b%10])
			return 1;
		else b/=10;
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n;
	for (int i = 1; i * i <= n; i++) if (!(n%i)) {
		ans += check(n, i);
		if (i*i != n)
			ans += check(n, n/i);
	}
	cout << ans;
	return 0;
}