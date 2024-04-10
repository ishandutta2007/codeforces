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


//#define int long long
#define endl "\n"
#define push_back emplace_back

int arr[2000][2000];
int cnt[2000][2000];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    //vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		char c;
    		cin >> c;
    		arr[i][j] = c - 'a';
    	}
    }
    //vector<vector<int>> cnt(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (i > 0) {
    			if (arr[i - 1][j] == arr[i][j]) {
    				cnt[i][j]++;
    			}
    		}
    		if (i < n - 1) {
    			if (arr[i + 1][j] == arr[i][j]) {
    				cnt[i][j]++;
    			}
    		}
    		if (j > 0) {
    			if (arr[i][j - 1] == arr[i][j]) {
    				cnt[i][j]++;
    			}
    		}
    		if (j < m - 1) {
    			if (arr[i][j + 1] == arr[i][j]) {
    				cnt[i][j]++;
    			}
    		}
    	}
    }
    vector<pair<int, int>> now;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (cnt[i][j] < 4) {
    			now.push_back(make_pair(i, j));
    		}
    	}
    }
    int ans = 0;
    int ind = 1;
    while (now.size() != 0) {
    	ans += now.size() * ind;
    	vector<pair<int, int>> now1;
    	for (int i1 = 0; i1 < now.size(); i1++) {
    		int i = now[i1].first;
    		int j = now[i1].second;
    		if (i > 0) {
    			if (arr[i - 1][j] == arr[i][j]) {
    				if (cnt[i - 1][j] == 4) {
    					now1.push_back(i - 1, j);
    				}
    				cnt[i - 1][j]--;
    			}
    		}
    		if (i < n - 1) {
    			if (arr[i + 1][j] == arr[i][j]) {
    				if (cnt[i + 1][j] == 4) {
    					now1.push_back(i + 1, j);
    				}
    				cnt[i + 1][j]--;
    			}
    		}
    		if (j > 0) {
    			if (arr[i][j - 1] == arr[i][j]) {
    				if (cnt[i][j - 1] == 4) {
    					now1.push_back(i, j - 1);
    				}
    				cnt[i][j - 1]--;
    			}
    		}
    		if (j < m - 1) {
    			if (arr[i][j + 1] == arr[i][j]) {
    				if (cnt[i][j + 1] == 4) {
    					now1.push_back(i, j + 1);
    				}
    				cnt[i][j + 1]--;
    			}
    		}
    	}
    	now = now1;
    	ind++;
    }
    cout << ans;
}