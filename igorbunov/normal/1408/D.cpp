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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr1(n);
    vector<pair<int, int>> arr2(m);
    for (int i = 0; i < n; i++) {
    	cin >> arr1[i].first >> arr1[i].second;
    }
    for (int i = 0; i < m; i++) {
    	cin >> arr2[i].first >> arr2[i].second;
    }

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		arr.push_back(make_pair(max(arr2[j].first + 1 - arr1[i].first, 0LL), max(arr2[j].second + 1 - arr1[i].second, 0LL)));
    		//cout << arr.back().firstb << " " << arr.back().second << endl;
    	}
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
    	//cout << arr[i].first << " " << arr[i].second << endl;
    }
    //cout << endl;
    vector<int> suf(arr.size());
    suf[arr.size() - 1] =  arr[arr.size() - 1].second;
    for (int i = (int)arr.size() - 2; i >= 0; i--) {
    	suf[i] = max(suf[i + 1], arr[i].second);
    	//cout << suf[i] << " d " << arr[i].second << endl;
    }
    int ans = suf[0];
    for (int i = 0; i < arr.size(); i++) {
    	int now = arr[i].first;
    	if (i != arr.size() - 1) {
    		now += suf[i + 1];
    	}
    	//cout << now << " " << suf[i + 1] << endl;
    	ans = min(ans, now);
    }

    cout << ans;

}