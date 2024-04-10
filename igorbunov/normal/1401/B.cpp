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

int calc (int a, int b) {
	if (a > b) {
		return a * b;
	}
	if (a == b) {
		return 0;
	}
	if (a < b) {
		return -1 * a * b;
	}
}

void solve() {
	vector<int> arr1(3), arr2(3);
	cin >> arr1[0] >> arr1[1] >> arr1[2];
	cin >> arr2[0] >> arr2[1] >> arr2[2];
	int ans = 0;
	ans += min(arr1[2], arr2[1]) * 2;
	int k = min(arr1[2], arr2[1]);
	arr1[2] -= k;
	arr2[1] -= k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 2) {
				continue;
			}
			if (i != -1 && j != 2) {
                continue;
			}
			k = min(arr1[i], arr2[j]);
			arr1[i] -= k;
			arr2[j] -= k;
		}
	}
	//cout << ans << " ";
	ans -= min(arr1[1], arr2[2]) * 2;
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