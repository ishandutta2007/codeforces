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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n - 1);
    vector<int> b(n - 1);

    for (int i = 0; i < n - 1; i++) {
    	cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
    	cin >> b[i];
    }

    vector<int> ans(n);

    for (int r = 1; r < 3; r++) {
    	vector<int> a1(n - 1);
    	vector<int> b1(n - 1);

    	for (int i = 0; i < n - 1; i++) {
    		if ((a[i] & r) != 0) {
    			a1[i] = 1;
    		}

    		if ((b[i] & r) != 0) {
    			b1[i] = 1;
    		}
    	}

    	vector<int> arr(n);

    	bool can = false;
    	for (arr[0] = 0; arr[0] < 4; arr[0]++) {
    		for (int i = 1; i < n; i++) {
    			if (arr[i - 1] == 0) {
    				arr[i] = a1[i - 1];
    			} else {
    				arr[i] = b1[i - 1];
    			}
    		}
    		bool good = true;
    		for (int i = 0; i < n - 1; i++) {
    			if ((arr[i] & arr[i + 1]) != b1[i]) {
    				good = false;
    			}

    			if ((arr[i] | arr[i + 1]) != a1[i]) {
    				good = false;
    			}
    		}

    		if (good) {
    			can = true;
    			for (int i = 0; i < n; i++) {
    				ans[i] += r * arr[i];
    			}
    			break;
    		}
    	}

    	if (!can) {
    		cout << "NO";
    		return 0;
    	}
    }

    cout << "YES\n";

    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
}