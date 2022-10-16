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
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr1[i];
    }
    vector<int> arr2(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr2[i];
    }
    vector<int> arr3(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr3[i];
    }
    vector<int> ans(n);
    ans[0] = arr1[0];
    for (int i = 1; i < n - 1; i++) {
    	if (ans[i - 1] != arr1[i]) {
    		ans[i] = arr1[i];
    		continue;
    	}
    	if (ans[i - 1] != arr2[i]) {
    		ans[i] = arr2[i];
    		continue;
    	}
    	if (ans[i - 1] != arr3[i]) {
    		ans[i] = arr3[i];
    		continue;
    	}
    }
    if (arr1[n - 1] != ans[n - 2] && arr1[n - 1] != ans[0]) {
    	ans[n - 1] = arr1[n - 1];
    }
    if (arr2[n - 1] != ans[n - 2] && arr2[n - 1] != ans[0]) {
    	ans[n - 1] = arr2[n - 1];
    }
    if (arr3[n - 1] != ans[n - 2] && arr3[n - 1] != ans[0]) {
    	ans[n - 1] = arr3[n - 1];
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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