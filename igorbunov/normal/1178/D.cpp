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
	vector<bool> ez(10000);

	int n;
	cin >> n;
	
	for (int i = 2; i < 10000; i++) {
		ez[i] = check(i);
	}

	vector<pair<int, int>> ans;

	for (int i = 0; i < n; i++) {
		ans.push_back(make_pair(i, (i + 1) % n));
	}

	for (int i = 0; i <= n; i += 2) {
		if (ez[(i * 3 + (n - i) * 2) / 2]) {

			int now = i / 2;

			if (now > 0) {
				ans.push_back(make_pair(0, (n + 1) / 2));
				now--;
			}

			for (int j = 0; j < now; j++) {
				ans.push_back(make_pair((j + 1) % n, (j + 1 + (n + 1) / 2) % n));
			}

			cout << ans.size() << endl;

			for (int j = 0; j < ans.size(); j++) {
				cout << ans[j].first + 1 << " " << ans[j].second + 1 << endl;
			}	

			return 0;	
		}
	}
}