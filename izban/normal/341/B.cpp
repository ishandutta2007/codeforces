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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn], d[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	memset(d, 127, sizeof(d));
	d[0] = -1;
	for (int i = 0; i < n; i++) {
		int j = lower_bound(d, d + n + 1, a[i]) - d;
		d[j] = a[i];
	}
	for (int i = n; i >= 0; i--) {
		if (d[i] < 1e9) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}