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

bool can(vector<int> a, vector<int> b) {
	if (!a[0] && !b[0]) {
		return true;
	}

	if (!a[1] && !b[1]) {
		return true;
	}

	return false;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n, vector<int>(2));

    int ban = 0;

    for (int i = 0; i < q; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--;
    	y--;
    	if (y > 0) {
    		if (!can(arr[y], arr[y - 1])) {
    			ban--;
    		}
    		if (arr[y][x]) {
    			arr[y][x] = 0;
    		} else {
    			arr[y][x] = 1;
    		}

    		if (!can(arr[y], arr[y - 1])) {
    			ban++;
    		}

    		if (arr[y][x]) {
    			arr[y][x] = 0;
    		} else {
    			arr[y][x] = 1;
    		}
    	}

    	if (y < n - 1) {
    		if (!can(arr[y], arr[y + 1])) {
    			ban--;
    		}
    		if (arr[y][x]) {
    			arr[y][x] = 0;
    		} else {
    			arr[y][x] = 1;
    		}

    		if (!can(arr[y], arr[y + 1])) {
    			ban++;
    		}

    		if (arr[y][x]) {
    			arr[y][x] = 0;
    		} else {
    			arr[y][x] = 1;
    		}
    	}

    	if (arr[y][x]) {
			arr[y][x] = 0;
		} else {
			arr[y][x] = 1;
		}

		if (ban == 0) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}


    }
}