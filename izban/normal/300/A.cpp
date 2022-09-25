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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 7;
const int mod = 1000000007;

int n, v[maxn], f[maxn];
vector<int> a[3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v, v + n);
	a[0].push_back(v[0]); f[0] = 1;
	if (v[n - 1] > 0) {
		a[1].push_back(v[n - 1]); f[n - 1] = 1;
	} else {
		a[1].push_back(v[1]); f[1] = 1;
		a[1].push_back(v[2]); f[2] = 1;
	}
	for (int i = 0; i < n; i++) if (!f[i]) a[2].push_back(v[i]);
	
	for (int i = 0; i < 3; i++) {
		cout << a[i].size() << " ";
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << " \n"[j == (int)a[i].size() - 1];
	}

	return 0;
}