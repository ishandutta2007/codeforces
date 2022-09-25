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
#include <cstring>
#include <cstdlib>

using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = -1;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
	int n, m;
	while (cin >> n >> m) {
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<char> less(n);

		int ans = 0;
		for (int j = 0; j < m; j++) {
			bool ok = 1;
			for (int i = 0; i + 1 < n; i++) {
				ok &= less[i] || a[i][j] <= a[i + 1][j];
			}
			if (ok) {
				for (int i = 0; i + 1 < n; i++) less[i] |= a[i][j] < a[i + 1][j];
			} else ans++;
		}
		cout << ans << endl;
	}

    return 0;
}