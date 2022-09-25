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

const int maxn = 310000;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn];
ll sum[maxn];

bool reading() {
	if (!(cin >> n)) return 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	return 1;
}

void fastsolve() {
	map<int, int> last;
	for (int i = 0; i < n; i++) last[a[i]] = i;
	sum[0] = a[0] >= 0 ? a[0] : 0;
	for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + (a[i] >= 0 ? a[i] : 0);

	ll ans = -1e18;
	int ansi = -1;
	for (int i = 0; i < n; i++) {
		int j = last[a[i]];
		if (i == j) continue;
		ll cans = 0;
		cans += sum[j];
		cans -= i ? sum[i - 1] : 0;
		if (a[i] < 0) cans += 2 * a[i];
		if (cans > ans) {
			ans = cans;
			ansi = i;
		}
	}

	vector<int> v;
	for (int i = 0; i < ansi; i++) v.push_back(i);
	for (int i = ansi + 1; i < last[a[ansi]]; i++) if (a[i] < 0) v.push_back(i);
	for (int i = last[a[ansi]] + 1; i < n; i++) v.push_back(i);
	cout << ans << " " << v.size() << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] + 1 << " \n"[i + 1 == v.size()];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (reading()) fastsolve();

	return 0;
}