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
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	int n, m;
	cin >> n >> m;

	int now = 0LL;

	int now1 = 0;
	int now2 = 0;

	for (int i = 0; i < n; i++) {
		now1 += i;
	}

	int j = n / 2;

	for (int i = j; i >= 0; i--) {
		now2 += (j - i);
	}

	for (int i = j; i < n; i++) {
		now2 += (i - j);
	}

	//cout << now1 << " " << now2 << endl;

	for (int i = 0; i < m; i++) {
		int x, d;
		cin >> x >> d;

		if (d >= 0) {
			now += x * n + now1 * d;
		} else {
			now += x * n + now2 * d;
		}
	}

	cout << fixed << setprecision(6) << (double)(now) / (double)n; 
}