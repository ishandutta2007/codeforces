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

int n, m, k;
int a[maxn], b[maxn];

string solve() {
	sort(a, a + n);
	sort(b, b + m);

	/*int i = 0;
	for (int j = 0; j < m; j++) {
		while (i < n && a[i] < b[j]) i++;
		if (i == n) {
			return "NO";
		}
		i++;
	}
	return "YES";*/

	int i = n - 1;
	for (int j = m - 1; j >= 0; j--) {
		if (i < 0) {
			return "NO";
		}
		if (a[i] > b[j]) {
			return "YES";
		}
		i--;
	}
	if (n <= m) return "NO";
	else return "YES";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> m >> k) {
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int j = 0; j < m; j++) cin >> b[j];
		cout << solve() << endl;
	}

	return 0;
}