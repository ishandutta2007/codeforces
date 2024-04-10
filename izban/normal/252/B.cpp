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

int n, a[maxn];
vector<int> v;

bool check() {
	bool res1 = true, res2 = true;
	for (int i = 0; i < n - 1; i++)
		res1 &= a[i] <= a[i + 1];
	for (int i = 0; i < n - 1; i++)
		res2 &= a[i] >= a[i + 1];
	return !(res1 || res2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	v.push_back(0);
	for (int i = 1; i < n; i++)
		if (a[i] != a[i - 1] || a[i] == a[i - 1] && (a[i] != a[i - 2] || i < 2))
			v.push_back(i);

	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v.size(); j++)
			if (a[v[i]] != a[v[j]]) {
				swap(a[v[i]], a[v[j]]);
				if (check()) {
					cout << v[i] + 1 << " " << v[j] + 1 << "\n";
					return 0;
				}
				swap(a[v[i]], a[v[j]]);
			}
	cout << -1;

	return 0;
}