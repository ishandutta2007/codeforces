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

const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn];
vector<pair<int, int> > v;
vector<int> o[3];

bool rec(int x) {
	bool ok = true;
	for (int i = 0; i < n; i++) ok &= a[i] == i + 1;
	if (ok) {
		cout << v.size() << endl;
		for (int i = (int)v.size() - 1; i >= 0; i--) cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
		return true;
	}
	
	if (x == 3) return false;

	o[x].clear();
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1) {
			o[x].push_back(i);
			continue;
		}
		if (a[i] - a[i - 1] != a[i + 1] - a[i] || abs(a[i] - a[i - 1]) != 1) o[x].push_back(i);
	}
	for (int i = (int)o[x].size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < o[x].size(); j++) {
			reverse(a + o[x][i], a + o[x][j] + 1);
			v.push_back(make_pair(o[x][i], o[x][j]));
			if (rec(x + 1)) return true;
			v.pop_back();
			reverse(a + o[x][i], a + o[x][j] + 1);
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	/*n = 1000;
	for (int i = 0; i < n; i++) a[i] = i + 1;
	reverse(a + 209, a + 273);
	reverse(a + 258, a + 402);
	reverse(a + 244, a + 784);
	cout << n << endl;
	for (int i = 0; i < n; i++) cout << a[i]<< " ";
	cout << endl;
	return 0;
	*/

	if (cin >> n) {
		v.clear();
		for (int i = 0; i < n; i++) cin >> a[i];
		rec(0);
	}
	
	return 0;
}