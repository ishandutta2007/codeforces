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
	int n, q;
	cin >> n;
	vector<int> arr(n);

	vector<pair<int, pair<int, int>>> tasks;


	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		tasks.push_back(make_pair(1, make_pair(i + 1, x)));
	}

	cin >> q;

	vector<int> suf(n + q + 1);

	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;

		if (type == 1) {
			int p, x;
			cin >> p >> x;
			tasks.push_back(make_pair(1, make_pair(p, x)));
		} else {
			int x;
			cin >> x;
			tasks.push_back(make_pair(2, make_pair(x, x)));
		}
	}

	suf[n + q] = -1;

	for (int i = n + q - 1; i >= 0; i--) {
		if (tasks[i].first == 2) {
			suf[i] = max(suf[i + 1], tasks[i].second.first);
		} else {
			suf[i] = suf[i + 1];
		}
	}

	vector<int> ans(n);
	for (int i = 0; i < n + q; i++) {
		if (tasks[i].first == 1) {
			int p = tasks[i].second.first;
			int x = tasks[i].second.second;
			p--;

			ans[p] = max(x, suf[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}