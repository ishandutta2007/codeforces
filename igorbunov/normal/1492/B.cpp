#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

//#define endl "\n"
#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> inds(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		inds[p[i]] = i;
	}

	vector<bool> used(n);
	vector<int> ans;
	int last = n;
	for (int i = n - 1; i >= 0; i--) {
		if (used[i] == true) {
			continue;
		}
		for (int j = inds[i]; j < last; j++) {
			ans.push_back(p[j]);
			used[p[j]] = true;
		}
		last = inds[i];
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
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