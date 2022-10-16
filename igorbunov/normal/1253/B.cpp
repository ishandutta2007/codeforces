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

    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    vector<int> count1(1000001);

    vector<int> ans;
    int balance = 0;

    for (int i = 0; i < n; i++) {
    	if (arr[i] < 0) {
    		count1[arr[i] * -1]--;
    		if (count1[arr[i] * -1] < 0) {
    			cout << -1;
    			return 0;
    		}
    		if (count1[arr[i] * -1] == 0) {
    			balance--;
    		}
    	} else {
    		if (count1[arr[i]] == 0) {
    			balance++;
    		}
    		count1[arr[i]]++;
    	}

    	if (balance == 0) {
    		ans.push_back(i + 1);
    	}
    }
    if (ans.size() == 0 || ans.back() != n) {
    	cout << -1;
    	return 0;
    }

    vector<int> count2(1000001);

    for (int i = 0; i < ans.size(); i++) {
    	if (i == 0) {
    		int first = 0;
    		int second = ans[i];

    		for (int j = first; j < second; j++) {
    			if (arr[j] > 0) {
    				count2[arr[j]]++;
    				if (count2[arr[j]] == 2) {
    					cout << -1;
    					return 0;
    				}
    			}
    		}

    		for (int j = first; j < second; j++) {
    			if (arr[j] > 0) {
    				count2[arr[j]]--;
    			}
    		}
    	} else {
    		int first = ans[i - 1];
    		int second = ans[i];

    		for (int j = first; j < second; j++) {
    			if (arr[j] > 0) {
    				count2[arr[j]]++;
    				if (count2[arr[j]] == 2) {
    					cout << -1;
    					return 0;
    				}
    			}
    		}

    		for (int j = first; j < second; j++) {
    			if (arr[j] > 0) {
    				count2[arr[j]]--;
    			}
    		}
    	}
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	if (i == 0) {
    		cout << ans[i] << " ";
    	} else {
    		cout << ans[i] - ans[i - 1] << " ";
    	}
    }
}