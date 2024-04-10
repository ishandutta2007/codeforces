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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> arr1;
    for (int i = 0; i < n / 2; i++) {
    	arr1.push_back(arr[i]);
    }
    vector<int> arr2;
    for (int i = 0; i < (n + 1) / 2; i++) {
    	arr2.push_back(arr[i + (n / 2)]);
    }
    //cout << arr1.size() << " " << arr2.size() << endl;
    vector<int> ans(n);
    for (int i = 0; i < n; i += 2) {
    	ans[i] = arr2[i / 2];
    }
    int ind = 0;
    for (int i = n - 1 - (n % 2); i >= 0; i -= 2) {
    	ans[i] = arr1[ind];
    	ind++;
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
    	if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
    		cnt++;
    	}
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }


}