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

bool check(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k1;
    cin >> n >> k1;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }

    map<int, int> m;

    for (int i = 0; i < n; i++) {
    	vector<pair<int, int>> now;

    	for (int j = 2; j * j <= arr[i]; j++) {
    		if (arr[i] % j == 0) {
    			if (now.size() == 0 || now.back().first != j) {
    				now.push_back(make_pair(j, 1));
    			} else {
    				now.back().second++;
    			}
    			arr[i] /= j;
    			j--;
    		}
    	}

    	if ( now.size() == 0 || now.back().first != arr[i]) {
    		if (arr[i] != 1) {
    			now.push_back(make_pair(arr[i], 1));
    		}
    	} else {
    		if (arr[i] != 1) {
    			now.back().second++;
    		}
    	}

    	for (int j = 0; j < now.size(); j++) {
    		//cout << now[j].first << " " << now[j].second << endl;
    		now[j].second %= k1;
    	}
    	arr[i] = 1;
    	for (int j = 0; j < now.size(); j++) {
    		for (int k = 0; k < now[j].second; k++) {
    			arr[i] *= now[j].first;
    		}
    	}

    	m[arr[i]]++;
    	//cout << arr[i] << endl;

    	//cout << endl;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
    	vector<pair<int, int>> now;

    	int last = arr[i];

    	for (int j = 2; j * j <= arr[i]; j++) {
    		if (arr[i] % j == 0) {
    			if (now.size() == 0 || now.back().first != j) {
    				now.push_back(make_pair(j, 1));
    			} else {
    				now.back().second++;
    			}
    			arr[i] /= j;
    			j--;
    		}
    	}

    	if ( now.size() == 0 || now.back().first != arr[i]) {
    		if (arr[i] != 1) {
    			now.push_back(make_pair(arr[i], 1));
    		}
    	} else {
    		if (arr[i] != 1) {
    			now.back().second++;
    		}
    	}
    	int now2 = 1;
    	for (int j = 0; j < now.size(); j++) {
    		for (int k = 0; k < k1 - now[j].second; k++) {
    			now2 *= now[j].first;
    		}
    	}

    	ans += m[now2];

    	arr[i] = last;

    	if (now2 == arr[i]) {
    		ans--;
    	}
    }

    cout << ans / 2;


}