



#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	n++;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int st = -1;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] > 1 && a[i + 1] > 1)
			st = i;
	}
	if (st == -1) {
		cout << "perfect";
		return 0;
	}
	cout << "ambiguous\n";
	int lst = 0;
	int m = 0;
	for (int i = 0; i < n; i++)
		m += a[i];
	vector<int> p1(m), p2(m);
	int now = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++)
			p1[now + j] = lst;
		now += a[i];
		lst = now;
	}

	now = 0;
	lst = 0;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			if (i != st + 1 || j) {
				p2[now + j] = lst;
			}
			else {
				p2[now + j] = lst - 1;
			}
		}
		now += a[i];
		lst = now;
	}

	for (int i : p1)
		cout << i << ' ';
	cout << '\n';
	for (int i : p2)
		cout << i << ' ';

	return 0;
}