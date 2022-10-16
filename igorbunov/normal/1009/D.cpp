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

int gcd(int a, int b) {
	if (!b) {
		return a;
	}

	return gcd(b, a % b);
}

signed main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> ans;

	if (m < n - 1) {
		cout << "Impossible";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (ans.size() == m) {
			break;
		}
		for (int j = i + 1; j <= n; j++) {
			if (gcd(i, j) == 1) {
				ans.push_back(make_pair(i, j));
				if (ans.size() == m) {
					break;
				}
			}
		}
	}

	if (ans.size() == m) {
		cout << "Possible\n";

		for (int i = 0; i < m; i++) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	} else {
		cout << "Impossible";
	}
}