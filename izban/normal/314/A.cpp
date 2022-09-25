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

const int maxn = 1 << 18;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k, m;
int a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> k;
	ll cur = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (cur - 1LL * (i - 1 - m) * (n - i) * a[i] < k) 
			cout << i << " ", m++;
		else 
			cur += a[i] * (i - 1 - m);
	}

	return 0;
}