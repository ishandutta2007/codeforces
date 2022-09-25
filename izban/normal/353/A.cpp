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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int x[maxn], y[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		int sx = 0, sy = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			sx += x[i];
			sy += y[i];
		}
		if (sx % 2 == 0 && sy % 2 == 0) {
			cout << 0 << endl;
			continue;
		}
		
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			if ((sx + sy) % 2 == 0 && (x[i] + y[i]) % 2 == 1) {
				ok = 1;
				cout << 1 << endl;
				break;
			}
		}
		if (!ok) cout << -1 << endl;
	}

	return 0;
}