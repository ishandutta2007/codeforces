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
#define double long double

void solve() {
	int n;
    double l1;
    cin >> n >> l1;
    vector<double> arr(n);
    vector<double> arr1(n);
    double ans;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    	arr1[(n - 1) - i] = (l1 - arr[i]);
    }
    double l = 0;
    double r = l1;
    while (r - l > 0.00000001) {
    	double m = (l + r) / 2.0;
    	double t1 = 0;
    	double now = 1.0;
    	bool was = false;
    	for (int i = 0; i < n; i++) {
    		if (arr[i] > m) {
    			//cout << now << " a " << t1 << endl;
    			if (i == 0) {
    				t1 += m / now;
    			} else {
    				t1 += (m - arr[i - 1]) / now;
    			}
    			was = true;
    			break;
    		}
    		if (i == 0) {
    			t1 += arr[0] / now;
    		} else {
    			t1 += (arr[i] - arr[i - 1]) / now;
    		}
    		now += 1.0;
    	}
    	if (!was) {
    		t1 += (m - arr[n - 1]) / now;
    	}
    	double t2 = 0.0;
    	swap(arr, arr1);
    	m = l1 - m;
    	was = false;
    	now = 1.0;
    	for (int i = 0; i < n; i++) {
    		if (arr[i] > m) {
    			//cout << now << " a " << t2 << endl;
    			if (i == 0) {
    				t2 += m / now;
    			} else {
    				t2 += (m - arr[i - 1]) / now;
    			}
    			was = true;
    			break;
    		}
    		if (i == 0) {
    			t2 += arr[0] / now;
    		} else {
    			t2 += (arr[i] - arr[i - 1]) / now;
    		}
    		now += 1.0;
    	}
    	if (!was) {
    		t2 += (m - arr[n - 1]) / now;
    	}
    	m = l1 - m;
    	swap(arr, arr1);
    	//cout << m << " " << t1 << " " << t2 << endl;
    	if (t1 < t2) {
    		l = m;
    		ans = t1;
    	} else {
    		ans = t1;
    		r = m;
    	}
    }
    cout << fixed << setprecision(8) << ans << endl;
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