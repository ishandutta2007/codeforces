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

signed main() {
	int q;
	cin >> q;
	for (int _ = 0; _ < q; _++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> arr(n, vector<int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;

				arr[i][j] = c == '*';
			}
		}

		vector<int> arr1(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr1[i] += arr[i][j] == 0;
			}
		}

		vector<int> arr2(m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr2[j] += arr[i][j] == 0;
			}
		}


		int ans = 1000000000LL;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int now = arr1[i] + arr2[j];
				now -= (arr[i][j] == 0);
				ans = min(ans, now);
			}
		}
		cout << ans << endl;
	}
}