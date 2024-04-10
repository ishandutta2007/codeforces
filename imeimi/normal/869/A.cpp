#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef unsigned long long llong;
typedef long double ld;
typedef pair<int, int> pi;

int n;
int x[2000];
int y[2000];
int a[4000];

bool bs(int x) {
	int s = 0, e = 2 * n - 1, m;
	while (s <= e) {
		m = (s + e) / 2;
		if (a[m] == x) return true;
		if (a[m] < x) s = m + 1;
		else e = m - 1;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		a[i] = x[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> y[i];
		a[i + n] = y[i];
	}
	sort(a, a + 2 * n);
	int c = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (bs(x[i] ^ y[j])) ++c;
		}
	}
	printf(c % 2 == 0 ? "Karen\n" : "Koyomi\n");
	return 0;
}