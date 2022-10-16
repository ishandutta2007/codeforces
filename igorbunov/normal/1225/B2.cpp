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

#pragma GCC_OPTIMAZE("ofast")

using namespace std;


#define int long long
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<int> count(1000000);
    for (int _ = 0; _ < t; _++) {
    	int n, k, d;
    	cin >> n >> k >> d;

    	vector<int> arr(n);
    	for (int i = 0; i < n; i++) {
    		cin >> arr[i];
    	}

    	set<int> now;

    	int ans = 100000000LL;

    	for (int i = 0; i < d; i++) {
    		if (count[arr[i]] == 0) {
    			now.insert(arr[i]);
    		}
    		count[arr[i]]++;
    	}
    	ans = now.size();
    	for (int i = d; i < n; i++) {
    		count[arr[i - d]]--;
    		if (count[arr[i - d]] == 0) {
    			now.erase(arr[i - d]);
    		}
    		if (count[arr[i]] == 0) {
    			now.insert(arr[i]);
    		}
    		count[arr[i]]++;

    		ans = min(ans, (int)now.size());
    	}
    	for (int i = n - d; i < n; i++) {
    		count[arr[i]]--;
    	}
    	cout << ans << endl;
    }
}