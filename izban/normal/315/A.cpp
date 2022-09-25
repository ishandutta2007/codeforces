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

int n, a[maxn], b[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n) {
		int ans = 0;
		for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
		for (int i = 0; i < n; i++) {
			bool f = 1;
			for (int j = 0; j < n; j++) if (j != i && b[j] == a[i]) f = 0;
			ans += f;
		}
		cout << ans << endl;
	}

	return 0;
}