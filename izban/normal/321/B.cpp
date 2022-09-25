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

const int maxn = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
int a[maxn];
vector<int> atk, def;
string t[maxn];

bool reading() {
	if (!(cin >> n >> m)) return 0;
	for (int i = 0; i < n; i++) {
		string T; int B;
		cin >> T >> B;
		if (T == "ATK") atk.push_back(B);
		if (T == "DEF") def.push_back(B);
	}
	for (int i = 0; i < m; i++) cin >> a[i];
	return 1;
}

int solveall() {
	vector<int> f(m, 1);
	for (int i = 0; i < def.size(); i++) {
		bool ok = 0;
		for (int j = 0; j < m; j++) if (f[j] && a[j] > def[i]) {
			f[j] = 0;
			ok = 1;
			break;
		}
		if (!ok) return 0;
	}

	int res = 0;
	for (int i = 0; i < atk.size(); i++) {
		bool ok = 0;
		for (int j = 0; j < m; j++) if (f[j] && a[j] >= atk[i]) {
			f[j] = 0;
			ok = 1;
			res += a[j] - atk[i];
			break;
		}
		if (!ok) return 0;
	}
	for (int i = 0; i < m; i++) if (f[i]) res += a[i];
	return res;
}

int solveatk(int x) {
	int res = 0;
	for (int i = x, j = m - 1; i >= 0; i--, j--) {
		res += max(0, a[j] - atk[i]);
	}
	return res;
}

int solve() {
	int res = -1;
	sort(a, a + m);
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	if (m > n) res = max(res, solveall());
	for (int i = 0; i < min((int)atk.size(), m); i++) res = max(res, solveatk(i));
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (reading()) cout << solve() << endl;

	return 0;
}