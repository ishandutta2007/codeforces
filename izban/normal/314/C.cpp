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

const int maxn = 1e6 + 1;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn];
vector<int> t;

void upd(int x, int y) {
	for (int i = x; i < maxn; i |= i + 1)
		t[i] = (t[i] + y) % mod;
}

int sum(int x) {
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		res = (res + t[i]) % mod;
	return res % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	scanf("%d", &n);
	t.assign(1e6 + 1, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int x = sum(a[i]);
		int y = (sum(a[i]) - sum(a[i] - 1) + mod) % mod;
		upd(a[i], (-y + mod) % mod);
		upd(a[i], (1LL * x * a[i] + a[i]) % mod);
	}
	cout << sum(1e6) << endl;

	return 0;
}