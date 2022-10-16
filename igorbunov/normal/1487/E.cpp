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

#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;
	vector<int> a1(n1);
	for (int i = 0; i < n1; i++) {
		cin >> a1[i];
	}
	vector<int> a2(n2);
	for (int i = 0; i < n2; i++) {
		cin >> a2[i];
	}
	vector<int> a3(n3);
	for (int i = 0; i < n3; i++) {
		cin >> a3[i];
	}
	vector<int> a4(n4);
	for (int i = 0; i < n4; i++) {
		cin >> a4[i];
	}

	vector<vector<int>> g1(n1);

	int m1;
	cin >> m1;
	for (int i = 0; i < m1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g1[a].push_back(b);
	}

	vector<vector<int>> g2(n2);

	int m2;
	cin >> m2;
	for (int i = 0; i < m2; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g2[a].push_back(b);
	}

	vector<vector<int>> g3(n3);

	int m3;
	cin >> m3;
	for (int i = 0; i < m3; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g3[a].push_back(b);
	}


	vector<int> dp4(n4), dp3(n3), dp2(n2), dp1(n1);
	set<pair<int, int>> now;
	for (int i = 0; i < n4; i++) {
		dp4[i] = a4[i];
		now.insert(make_pair(dp4[i], i));
	}

	for (int i = 0; i < n3; i++) {
		for (auto u: g3[i]) {
			now.erase(make_pair(dp4[u], u));
		}
		if (now.size() != 0) {
			dp3[i] = a3[i] += now.begin()->first;
		} else {
			dp3[i] = 1000000000000000LL;
		}
		for (auto u: g3[i]) {
			now.insert(make_pair(dp4[u], u));
		}
	}

	now.clear();
	for (int i = 0; i < n3; i++) {
		now.insert(make_pair(dp3[i], i));
	}

	for (int i = 0; i < n2; i++) {
		for (auto u: g2[i]) {
			now.erase(make_pair(dp3[u], u));
		}
		if (now.size() != 0) {
			dp2[i] = a2[i] += now.begin()->first;
		} else {
			dp2[i] = 1000000000000000LL;
		}
		for (auto u: g2[i]) {
			now.insert(make_pair(dp3[u], u));
		}
	}

	now.clear();
	for (int i = 0; i < n2; i++) {
		now.insert(make_pair(dp2[i], i));
	}


	for (int i = 0; i < n1; i++) {
		for (auto u: g1[i]) {
			now.erase(make_pair(dp2[u], u));
		}
		if (now.size() != 0) {
			dp1[i] = a1[i] += now.begin()->first;
		} else {
			dp1[i] = 1000000000000000LL;
		}
		for (auto u: g1[i]) {
			now.insert(make_pair(dp2[u], u));
		}
	}

	now.clear();
	for (int i = 0; i < n1; i++) {
		now.insert(make_pair(dp1[i], i));
	}

	if (now.size() == 0 || now.begin()->first >= 1000000000000000LL) {
		cout << -1;
	} else {
		cout << now.begin()->first;
	}
}