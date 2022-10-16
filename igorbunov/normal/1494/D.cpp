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

#define mod NE_mod
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"


int a[1000][1000];

int k;
vector<int> ans(1000000);
vector<pair<int, int>> re;
int MAIN;

void solve(vector<int> &inds, int root = -1) {
	if (inds.size() == 0) {
		return;
	}
	if (inds.size() == 1) {
		if (root != -1) {
			re.push_back(make_pair(inds[0], root));
		} else {
			MAIN = inds[0];
		}
		return;
	}
	int max1 = -1;
	for (auto v: inds) {
		for (auto u: inds) {
			if (a[v][u] > max1) {
				max1 = a[v][u];
			}
		}
	}
	ans[k] = max1;
	int root1 = k;
	if (root != -1) {
		re.push_back(make_pair(root1, root));
	} else {
		MAIN = root1;
	}
	k++;

	vector<bool> used(inds.size());
	for (int i = 0; i < inds.size(); i++) {
		if (used[i]) {
			continue;
		}
		vector<int> inds1;
		inds1.push_back(inds[i]);
		used[i] = true;
		for (int j = 0; j < inds.size(); j++) {
			if (used[j]) {
				continue;
			}
			if (a[inds[i]][inds[j]] != max1) {
				inds1.push_back(inds[j]);
				used[j] = true;
			}
		}
		solve(inds1, root1);
	}
	inds.clear();
}


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	k = n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		ans[i] = a[i][i];
	}
	vector<int> kek;
	for (int i = 0; i < n; i++) {
		kek.push_back(i);
	}
	solve(kek);
	cout << k << endl;
	for (int i = 0; i < k; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cout << MAIN + 1 << endl;

	for (int i = 0; i < re.size(); i++) {
		cout << re[i].first + 1 << " " << re[i].second + 1 << endl;
	}

}