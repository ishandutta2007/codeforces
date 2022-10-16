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

int dp[1000][1000];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    int kek = 1;
    while (kek * 2 <= n) {
    	kek *= 2;
    }
    for (int l = 0; l < 20; l++) {
    	for (int i = 0; i < n; i++) {
    		if (i / (1 << l) % 2) {
    			continue;
    		}
    		int next = i + (1 << l);
    		//cout << i << " " << next << endl;
    		if (next >= kek) {
    			break;
    		}
    		ans.push_back(make_pair(i + 1, next + 1));
    	}
    }
    for (int l = 0; l < 20; l++) {
    	for (int i = 0; i < n; i++) {
    		if ((i / (1 << l)) % 2) {
    			continue;
    		}
    		int next = i + (1 << l);
    		//cout << i << " " << next << endl;
    		if (next >= kek) {
    			break;
    		}
    		ans.push_back(make_pair(n - i, n - next));
    	}
    }
    /*vector<int> arr(n);
    for (int i = 0; i < n; i++) {
    	arr[i] = i;
    }
    for (int i = 0; i < 1000; i++) {
    	for (int j = 0; j < 1000; j++) {
    		dp[i][j] = rand() % 100;
    		dp[j][i] = dp[i][j];
    	}
    }*/

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	//int t = dp[arr[ans[i].first - 1]][arr[ans[i].second - 1]];
    	//arr[ans[i].first - 1] = t;
    	//arr[ans[i].second - 1] = t;

    	cout << ans[i].first << " " << ans[i].second << endl;
    }
    for (int i = 0; i < n; i++) {
    	//cout << arr[i] << " ";
    }
}