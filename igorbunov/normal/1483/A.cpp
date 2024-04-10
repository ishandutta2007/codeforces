#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <random>
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

#define s second
#define f first
#define push_back emplace_back

void solve() {
	int n, m;
	cin >> n >> m;
	int bad = ((m + 1) / 2);
	vector<int> cnt(n);
	vector<int> cnt1(n);
	vector<vector<int>> arr;
	bool flag = false;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		vector<int> now;
		for (int j = 0; j < k; j++) {
			int val;
			cin >> val;
			val--;
			now.push_back(val);
		}
		if (now.size() == 1) {
			cnt[now[0]]++;
		} else {
			for (auto kek: now) {
				cnt1[kek]++;
			}
		}
		arr.push_back(now);
	}
	for (int i = 0; i < n; i++) {
		if (cnt[i] > bad) {
			cout << "NO\n";
			return;
		}
	}
	int ind = -1;
	for (int i = 0; i < n; i++) {
		if (cnt1[i] + cnt[i] >= bad) {
			ind = i;
		}
	}
	if (ind != -1) {
		int ost = bad - cnt[ind];
		cout << "YES\n";
		for (int i = 0; i < m; i++) {
			if (arr[i].size() == 1) {
				cout << arr[i][0] + 1 << " ";
				continue;
			}
			bool was = false;
			for (auto kek: arr[i]) {
				if (kek == ind) {
					was = true;
				}
			}
			if (was && ost) {
				cout << ind + 1 << " ";
				ost--;
			} else {
				if (arr[i][0] == ind) {
					cout << arr[i][1] + 1 << " ";
				} else {
					cout << arr[i][0] + 1 << " ";
				}
			}
		}
		if (ost != 0) {
			exit(1);
		}
		cout << endl;
	} else {
		cout << "YES\n";
		for (int i = 0; i < m; i++) {
			cout << arr[i][0] + 1 << " ";
		}
		cout << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}