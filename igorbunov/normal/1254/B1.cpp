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
    vector<int> arr(n);

    int sum1 = 0;
    vector<int> pos(n + 2);
    vector<int> dist(n);
    vector<int> dist_suf(n);

    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    	if (i > 0) {
    		dist[i] = dist[i - 1] + sum1;
    	}
    	sum1 += arr[i];

    	//cout << dist[i] << " ";

    	if (arr[i] == 1) {
    		pos[sum1 - 1] = i;
    	}
    }
    int now1 = 0;
    for (int i = n - 1; i >= 0; i--) {
    	if (i < n - 1) {
    		dist_suf[i] = dist_suf[i + 1] + now1;
    	}
    	now1 += arr[i];
    }

    //cout << dist_suf[0] << endl;
    if (sum1 == 1) {
    	cout << -1;
    	return 0;
    }

    int ans = 10000000000LL;

    for (int i = 2; i <= n; i++) {
    	if (sum1 % i != 0) {
    		continue;
    	}

    	int now = 0LL;

    	for (int j = 0; j < sum1; j += i) {
    		int ind1 = j;
    		int ind2 = (j + (j + i - 1)) / 2;
    		int ind3 = (j + i - 1);
    		//cout << ind1 << " " << ind3 << " " << ind2 << "   ";
    		now += dist[pos[ind2]] - dist[pos[ind1]] - ind1 * (pos[ind2] - pos[ind1]);
    		now += dist_suf[pos[ind2]] - dist_suf[pos[ind3]] - (sum1 - 1 - ind3) * (pos[ind3] - pos[ind2]);
    	}
    	//cout << now;
    	ans = min(now, ans);
    	//cout << now;

    	//cout << endl;
    }

    cout << ans;
}