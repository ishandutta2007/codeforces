


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
	int n, a, b;
	cin >> n >> a >> b;
	for (int j = 0; j * 1ll * a <= n; j++) {
		if ((n - j * a) % b == 0) {
			int am = (n - j * a) / b;
			int pos = 1;
			for (int i = 0; i < j; i++) {
				for (int k = 0; k < a - 1; k++) {
					cout << ++pos << ' ';
				}
				pos++;
				cout << pos - a << ' ';
			}
			for (int i = 0; i < am; i++) {
				for (int k = 0; k < b - 1; k++) {
					cout << ++pos << ' ';
				}
				pos++;
				cout << pos - b << ' ';
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}