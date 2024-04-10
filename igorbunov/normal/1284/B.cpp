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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> arr(n);

    vector<int> bad_b;
    vector<int> bad_e;

    for (int i = 0; i < n; i++) {
    	int m;
    	cin >> m;
    	arr[i].resize(m);
    	for (int j = 0; j < m; j++) {
    		cin >> arr[i][j];
    	}


    	if (m > 1) {
    		bool can = false;

    		for (int j = 0; j < m - 1; j++) {
    			if (arr[i][j] < arr[i][j + 1]) {
    				can = true;
    			}
    		}


    		if (!can) {
    			bad_b.push_back(arr[i][0]);
    			bad_e.push_back(arr[i][m - 1]);
    		}
    	} else {
    		bad_b.push_back(arr[i][0]);
    		bad_e.push_back(arr[i][0]);
    	}
    }
    sort(bad_b.begin(), bad_b.end());
    sort(bad_e.begin(), bad_e.end());
    /*for (int i = 0; i < bad_b.size(); i++) {
    	cout << bad_b[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < bad_e.size(); i++) {
    	cout << bad_e[i] << " ";
    }
    cout << endl;*/
    int k1 = n - bad_b.size();
    int k2 = bad_b.size();

    int ans = 0;
    ans += 2 * k1 * n - k1 * k1;

    for (int i = 0; i < k2; i++) {
    	int now = bad_e[i];

    	auto keke = upper_bound(bad_b.begin(), bad_b.end(), now);
    	//cout << bad_b.end() - keke << endl;
    	ans += bad_b.end() - keke;
    }

    cout << ans;
}