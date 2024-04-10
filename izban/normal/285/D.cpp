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

const int maxn = 16;
const int inf = 1000000007;
const int mod = 1000000007;

int n, ans;
bool used1[maxn], used2[maxn];


void rec(int x) {
	if (x == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) if (!used1[i] && !used2[(x + i) % n] && (x != 0 || i == 0)) {
		used1[i] = 1;
		used2[(x + i) % n] = 1;
		rec(x + 1);
		used1[i] = 0;
		used2[(x + i) % n] = 0;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	const int res[17] = {0, 1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};
	cin >> n;
	cout << res[n] << endl;

	/*cout << "const int res[maxn] = {";
	for (n = 1; n <= 15; n += 2) {
		ans = 0;
		rec(0);
		ans = 1LL * ans * n % mod;
		for (int i = 1; i <= n; i++)
			ans = 1LL * ans * i % mod;
		cout << ans;
		if (n < 15) cout << ", 0, "; else cout << "};";
		cerr << n << endl;
	}*/

	return 0;
}