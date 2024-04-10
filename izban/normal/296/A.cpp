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


int n, a[maxn], cnt[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
		bool res = 1;
		for (int i = 1; i <= 1000; i++) res &= 2 * cnt[i] <= n + 1;
		if (res) cout << "YES"; else cout << "NO" << endl;
	}

	return 0;
}