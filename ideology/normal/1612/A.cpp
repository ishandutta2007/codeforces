#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
void add(int& x, int y) { if ((x += y) >= P) x -= P; }

int iabs(int x) { return x < 0 ? -x : x; }
int sgn(int x) { return x < 0 ? -1 : 1; }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int x1, y1, x2, y2; cin >> x2 >> y2; x1 = y1 = 0;
		int d = iabs(x1 - x2) + iabs(y1 - y2);
		if (d & 1) cout << "-1 -1\n";
		else {
			int vx = min(iabs(x1 - x2), d / 2), vy = d / 2 - vx;
			cout << (x1 + sgn(x2 - x1) * vx) << ' ' << (y1 + sgn(y2 - y1) * vy) << '\n';
		}
	}

	return 0;
}