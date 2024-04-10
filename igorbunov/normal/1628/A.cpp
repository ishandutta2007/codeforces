#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
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

#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> mex(n);
	set<int> now;
	for (int i = 0; i <= n + 1; i++) {
		now.insert(i);
	}
	for (int i = n - 1; i >= 0; i--) {
		now.erase(arr[i]);
		mex[i] = *(now.begin());
	}
	vector<int> ans;

	int L = 0;

	for (int i = 0; i <= n + 1; i++) {
		now.insert(i);
	}

	for (int i = 0; i < n; i++) {
		now.erase(arr[i]);
		if (mex[L] == *(now.begin())) {
			ans.push_back(mex[L]);
			for (int j = L; j <= i; j++) {
				now.insert(arr[j]);
			}
			//cout << "! " << L << " " << i << endl;
			L = i + 1;
		}
	}
	cout << ans.size() << endl;
	for (auto val: ans) {
		cout << val << " ";
	}
	cout << endl;
}
signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}