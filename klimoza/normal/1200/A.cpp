#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod = 998244353;

mt19937 mrand(random_device{} ());


signed main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	

	int n;
	cin >> n;
	vector<int> a(10, 0);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == 'L') {
			for (int j = 0; j < 10; j++) {
				if (a[j] == 0) {
					a[j] = 1;
					break;
				}
			}
		}
		else if (c == 'R') {
			for (int j = 9; j >= 0; j--) {
				if (a[j] == 0) {
					a[j] = 1;
					break;
				}
			}
		}
		else {
			a[c - '0'] = 0;
		}
	}
	for (int i : a) cout << i;
	return 0;
}