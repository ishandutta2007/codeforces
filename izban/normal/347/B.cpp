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
int a[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 0, res = 0;
		for (int i = 0; i < n; i++) ans += a[i] == i;
		for (int i = 0; i < n; i++) if (a[a[i]] == i && a[i] != i) { res++; break;}
		if (res == 0) ans = min(n, ans + 1);
		else ans += 2;
		cout << ans << endl;
	}

	return 0;
}