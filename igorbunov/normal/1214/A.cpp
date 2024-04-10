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
	int n, d, e;
	cin >> n >> d >> e;
	e *= 5;
	int ans = n;

	for (int i = 0; i < 100000; i++) {
		if (i * d <= n) {
			ans = min(ans, (n - i * d) % e);
		}
	}

	cout << ans;
}