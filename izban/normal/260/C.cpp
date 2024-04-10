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
#include <assert.h>
#include <memory.h>

using namespace std;

#define ll long long


#pragma comment(linker, "/STACK:64000000")
const int maxn = 1 << 17, maxk = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

int n, x;
long long a[maxn], y;
bool f;

void naive_sol() {
	int i = x;
	while (1) {
		if (i == 0) i = n;
		if (a[i])
			a[i--]--;
		else {
			a[i] = y;
			for (int i = 1; i <= n; i++)
				cout << a[i] << " ";
			return;
		}
		y++;
	}
}

void sol() {
	long long mn = inf;
	for (int i = 1; i <= n; i++)
		mn = min(mn, a[i]);
	for (int i = 1; i <= n; i++)
		a[i] -= mn;
	y = mn * n;
	naive_sol();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f |= !a[i];
	}

	if (f)
		naive_sol();
	else
		sol();

	return 0;
}