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
vector<int> a, b, c, e, a1[101], b1[101];

vector<int> get(vector<int> a, vector<int> b) {
	vector<int> c(a.size());
	for (int i = 0; i < a.size(); i++)
		c[i] = a[b[i]];
	return c;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	a.assign(n + 1, 0);
	b.assign(n + 1, 0);
	c.assign(n + 1, 0);
	e.assign(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		b[a[i]] = i;
	for (int i = 0; i <= n; i++)
		e[i] = i;

	a1[0] = e;
	for (int i = 0; i < k; i++)
		a1[i + 1] = get(a1[i], a);
	b1[0] = e;
	for (int i = 0; i < k; i++)
		b1[i + 1] = get(b1[i], b);

	bool ans = 0;
	if (c == e) {
		ans = k == 0 && a == e;
	} else {
		for (int i = 1; i <= k; i++)
			if (a1[i] == c) {
				if (k == i || (k - i) % 2 == 0 && a != b)
					ans = 1;
				break;
			}
		for (int i = 1; i <= k; i++) 
			if (b1[i] == c) {
				if (k == i || (k - i) % 2 == 0 && a != b)
					ans = 1;
				break;
			}
	}

	if (ans)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;


	return 0;
}