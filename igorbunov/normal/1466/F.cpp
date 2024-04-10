#include <algorithm>
#include <iostream>
#include <cstdlib>
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

//309810XU
#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"


void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(m);
	vector<int> colour(m);
	vector<bool> free(m);
	for (int i = 0; i < m; i++) {
		arr[i].push_back(i);
		colour[i] = i;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k == 1) {
			int a;
			cin >> a;
			a--;
			if (free[a]) {
				continue;
			}
			int c = colour[a];
			for (auto u: arr[c]) {
				free[u] = true;
			}
		} else {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			if (colour[a] == colour[b]) {
				continue;
			}
			if (free[a] && free[b]) {
				continue;
			}
			if (free[a] && !free[b]) {
				int c = colour[b];
				for (auto u: arr[c]) {
					free[u] = true;
				}
			}

			if (free[b] && !free[a]) {
				int c = colour[a];
				for (auto u: arr[c]) {
					free[u] = true;
				}
			}

			int c1 = colour[a];
			int c2 = colour[b];
			if (arr[c1].size() > arr[c2].size()) {
				for (auto u: arr[c2]) {
					colour[u] = c1;
					arr[c1].push_back(u);
				}
				arr[c2].clear();
			} else {
				for (auto u: arr[c1]) {
					colour[u] = c2;
					arr[c2].push_back(u);
				}
				arr[c1].clear();
			}
		}
		ans.push_back(i + 1);
	}
	int kek = 1;
	for (int i = 0; i < ans.size(); i++) {
		kek *= 2;
		kek %= (1000000007);
	}
	cout << kek << " " << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}