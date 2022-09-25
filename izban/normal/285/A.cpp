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

int n, k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	while (cin >> n >> k) {
		if (k == 0) {
			for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
			continue;
		}
		cout << n << " \n"[n == 1];
		for (int i = 1; i < k; i++) cout << n - i << " \n"[i == n - 1];
		for (int i = k; i < n; i++) cout << i - k + 1 << " \n"[i == n - 1];
	}

	return 0;
}