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

bool used[1000][1000];
bool arr[1000][1000];
int n, m;

void dfs(int x, int y) {
	//cout << x << " " << y << endl;
	used[x][y] = true;
	if (x > 0) {
		if (!used[x - 1][y] && arr[x - 1][y] == 1) {
			dfs(x - 1, y);
		}
	}

	if (y < m - 1) {
		if (!used[x][y + 1] && arr[x][y + 1] == 1) {
			dfs(x, y + 1);
		}
	}

	if (x < n - 1) {
		if (!used[x + 1][y] && arr[x + 1][y] == 1) {
			dfs(x + 1, y);
		}
	}

	if (y > 0) {
		if (!used[x][y - 1] && arr[x][y - 1] == 1) {
			dfs(x, y - 1);
		}
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;


    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		char c;
    		cin >> c;
    		if (c == '#') {
    			arr[i][j] = 1;
    		} else {
    			arr[i][j] = 0;
    		}
    	}
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
    	int st = 0;
    	bool lol = false;
    	for (int j = 0; j < m; j++) {
    		if (arr[i][j] == 1) {
    			lol = true;
    			if (st == 0) {
    				st = 1;
    				continue;
    			}
    			if (st == 2) {
    				cout << -1;
    				return 0;
    			}
    		} else {
	    		if (st == 1) {
	    			st = 2;
	    		}
	    	}
    	}
    	if (!lol) {
    		cnt1++;
    	}
    }
    int cnt2 = 0;
    for (int j = 0; j < m; j++) {
    	int st = 0;
    	bool lol = false;
    	for (int i = 0; i < n; i++) {
    		if (arr[i][j] == 1) {
    			lol = true;
    			if (st == 0) {
    				st = 1;
    				continue;
    			}
    			if (st == 2) {
    				cout << -1;
    				return 0;
    			}
    		} else {
	    		if (st == 1) {
	    			st = 2;
	    		}
	    	}
    	}
    	if (!lol) {
    		cnt2++;
    	}
    }
    if (cnt1 * cnt2 == 0 && (cnt1 + cnt2 > 0)) {
    	cout << -1;
    	return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (!used[i][j] && arr[i][j] == 1) {
    			//cout << endl;
    			dfs(i, j);
    			ans++;
    		}
    	}
    }

    cout << ans;


}