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
	vector<vector<int>> arr(n, vector<int>(n, 0));
	for (int i = 0; i < n - 1; i += 2) {
		arr[i][i] = 1;
		arr[i + 1][i] = 1;
		arr[i][i + 1] = 1;
		arr[i + 1][i + 1] = 1;
	}
	if (n % 2 == 1) {
		arr[n - 1][n - 2] = 1;
		arr[n - 2][n - 1] = 1;
		arr[n - 1][n - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
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