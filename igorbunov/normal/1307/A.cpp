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
	int n, d;
	cin >> n >> d;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	ans += arr[0];

	int now = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < arr[i]; j++) {
			if (now + i > d) {
				break;
			}
			now += i;
			ans++;
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