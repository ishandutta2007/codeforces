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
#include <ctime>
#include <cassert>

using namespace std;

#define ll long long
#define double long double

const int maxn = 1 << 17;
const int inf = 1000000007;


int n, k;
int d[maxn];
vector<int> v;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (v.empty() || v.back() != x)
			v.push_back(x);
	}

	int k = 1;
	for (int i = 0; i < v.size(); i++) {
		d[v[i]] += -(i > 0 && v[i - 1] != v[i]) - (i < (int)v.size() - 1 && v[i] != v[i + 1]) + (i > 0 && i < (int)v.size() - 1 && v[i - 1] != v[i + 1]);
		if (d[v[i]] < d[k] || d[v[i]] == d[k] && k > v[i])
			k = v[i];
	}

	cout << k;

	return 0;
}