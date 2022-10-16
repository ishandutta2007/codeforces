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

void solve() {
	int n, s, t;
	cin >> n >> s >> t;
	map<int, bool> m;
	vector<int> arr(t + 1);

	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		m[a] = true;
	}
	arr[t] = s;

	int ans = 10000000000000LL;

	for (int i = 0; i < t + 1; i++) {
		if (arr[i] != 1) {
			if (!m[arr[i] - 1]) {
				ans = min(ans, abs(s - (arr[i] - 1)));
			}
		}

		if (!m[arr[i]]) {
			ans = min(ans, abs(s - arr[i]));
		}

		if (arr[i] != n) {
			if (!m[arr[i] + 1]) {
				ans = min(ans, abs(s - (arr[i] + 1)));
			}
		}
	}
	cout << ans << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
    	solve();
    }
}