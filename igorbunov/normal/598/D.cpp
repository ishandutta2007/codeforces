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
using namespace std;
  
#define int long long
#define endl '\n'
typedef long double ld;

bool used[1000][1000];
int n, m;
char arr[1000][1000];
vector<pair<int, int>> now;
int now1 = 0;

void dfs(int x, int y) {
	if (used[x][y]) {
		return;
	}
	used[x][y] = true;
	now.push_back(make_pair(x, y));
	if (x > 0) {
		if (arr[x - 1][y] == '.') {
			dfs(x - 1, y);
		} else {
			now1++;
		}
	}

	if (x < n - 1) {
		if (arr[x + 1][y] == '.') {
			dfs(x + 1, y);
		} else {
			now1++;
		}
	}

	if (y > 0) {
		if (arr[x][y - 1] == '.') {
			dfs(x, y - 1);
		} else {
			now1++;
		}
	}

	if (y < m - 1) {
		if (arr[x][y + 1] == '.') {
			dfs(x, y + 1);
		} else {
			now1++;
		}
	}

}

int32_t main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> arr[i][j];
    	}
    }
    vector<vector<int>> ans(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (!used[i][j] && arr[i][j] == '.') {
    			//cout << "FLEX";
    			now.clear();
    			now1 = 0;
    			dfs(i, j);
    			//cout << now1 << endl;
    			for (int l = 0; l < now.size(); l++) {
    				auto p = now[l];
    				int x = p.first;
    				int y = p.second;
    				ans[x][y] = now1;
    			}
    		}
    	}
    }
    //cout << endl;
    for (int i = 0; i < q; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--;
    	y--;
    	cout << ans[x][y]<< endl;
    }

}