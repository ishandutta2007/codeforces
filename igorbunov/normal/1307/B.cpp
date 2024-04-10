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

 
//#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;

#define int long long
#define endl "\n"

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 1000000000000LL;

	for (int i = 0; i < n; i++) {

		if (arr[i] > x) {
			ans = min(ans, 2LL);
			continue;
		}
		if (x % arr[i] == 0) {
			ans = min(ans, x / arr[i]);
		} else {
			ans = min(ans, (x / arr[i]) + 1);
		}
	}

	cout << ans << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}