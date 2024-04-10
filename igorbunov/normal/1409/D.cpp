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
	int n, s;
    cin >> n >> s;
    int a = n;
    if (n== 1000000000000000000LL) {
    	cout << 0;
    	return;
    }
    if (n == 1000000000000000000LL - 1LL) {
    	if (s == 162) {
    		cout << 0;
    	} else {
    		cout << 1;
    	}
    	return;
    }
    vector<int> arr(19);
    int sum = 0;
    for (int i = 0; i < 19; i++) {
    	arr[i] = n % 10;
    	n /= 10;
    	sum += arr[i];
    }
    if (sum <= s) {
    	cout << 0;
    	return;
    }
    vector<int> pref(19);
    pref[0] = arr[0];
    for (int i = 1; i < 19; i++) {
    	pref[i] = pref[i - 1] + arr[i];
    }
    for (int i = 1; i < 19; i++) {
    	if (arr[i] != 9) {
    		if (sum - pref[i - 1] + 1 <= s) {
    			int ans = 0;
    			int st = 1;
    			for (int j = 0; j < i; j++) {
    				st *= 10;
    			}
    			ans += st * (arr[i] + 1);
    			st *= 10;
    			for (int j = i + 1; j < 19; j++) {
    				ans += st * arr[j];
    				st *= 10;
    			}
    			cout << ans - a;
    			return;
    		}
    	}
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
    	cout << endl;
    }
}