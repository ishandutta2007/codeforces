#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const double PHI = (sqrt(5.0) - 1) / 2.0;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, b;
	while (cin >> n >> b) {
		queue<ll> q;
		ll last = -1;
		for (int i = 0; i < n; i++) {
			ll t, d;
			cin >> t >> d;
			while (!q.empty() && q.front() <= t) {
				q.pop();
			}
			if (q.empty()) last = t;
			if (q.size() == b + 1) {
				cout << -1 << " \n"[i + 1 == n];
			}
			else {
				q.push(last + d);
				last += d;
				cout << last << " \n"[i + 1 == n];
			}
		}
	}

	return 0;
}