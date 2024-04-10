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
	int n;
	cin >> n;
	vector<int> arr(100009);
	int m = -1, c = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x]++;
		if (arr[x] > m) {
			m = arr[x];
			c = 0;
		}
		if (arr[x] == m) {
			c++;
		}
	}
	cout << (n - m * c) / (m - 1) + (c - 1) << endl;
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