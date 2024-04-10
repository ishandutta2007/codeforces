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
	int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		char c;
    		cin >> c;
    		if (c == 'D') {
    			arr[i][j] = 1;
    		}
    		if (c == 'R') {
    			arr[i][j] = 2;
    		}
    		if (c == 'C') {
    			arr[i][j] = 3;
    		}
    	}
    }
    int ans = 0;
    for (int j = 0; j < m - 1; j++) {
    	ans += (arr[n - 1][j] != 2);
    }
    for (int i = 0; i < n - 1; i++) {
    	ans += (arr[i][m - 1] != 1);
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