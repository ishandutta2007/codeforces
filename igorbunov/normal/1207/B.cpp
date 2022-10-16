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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> b(n, vector<int>(m));
	vector<pair<int, int>> ans;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {

			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1) {
				ans.push_back(make_pair(i + 1, j + 1));
				b[i][j] = 1;
				b[i + 1][j] = 1;
				b[i][j + 1] = 1;
				b[i + 1][j + 1] = 1;
			}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != b[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}