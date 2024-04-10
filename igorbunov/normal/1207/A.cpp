#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		a /= 2;

		int d, e;
		cin >> d >> e;

		if (d > e) {
			int ans = min(a, b) * d;

			int x = min(a, b);
			a -= x;
			b -= x;

			ans += min(a, c) * e;
			cout << ans;
		} else {
			int ans = min(a, c) * e;

			int y = min(a, c);
			a -= y;
			c -= y;

			ans += min(a, b) * d;
			cout << ans;
		}
		cout << endl;
	}
}