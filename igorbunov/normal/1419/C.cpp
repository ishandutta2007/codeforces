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
	int cnt = 0;
	int lol = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] == x) {
			cnt++;
		}
		lol += arr[i] - x;
	}
	if (cnt == n) {
		cout << 0 << endl;
		return;
	}
	if (lol == 0) {
		cout << 1 << endl;
		return;
	}
	if (cnt == 0) {
		cout << 2 << endl;
		return; 
	}
	if (cnt >= 1) {
		cout << 1 << endl;
		return;
	}
	cout << 2 << endl;
	return;
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