#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

//#define endl "\n"
#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> x(n); 
	vector<int> y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	if (n % 2 == 1) {
		cout << 1 << endl;
	} else {
		cout << (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << endl;
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}