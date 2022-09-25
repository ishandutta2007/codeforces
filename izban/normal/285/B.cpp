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

int n, s, t;
int a[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	while (cin >> n >> s >> t) {
		for (int i = 1; i <= n; i++) cin >> a[i];
		int cur = s, ans = 0;
		do {
			if (cur == t) {
				cout << ans << endl;
				break;
			}
			cur = a[cur];
			ans++;
		} while (cur != s);
		if (cur == s && t != s) cout << -1 << endl;
	}

	return 0;
}