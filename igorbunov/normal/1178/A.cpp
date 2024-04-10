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
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		sum += arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin() + 1, arr.end());

	int now = arr[0].first;
	vector<int> ans;
	ans.push_back(0);

	for (int i = 1; i < n; i++) {
		if (arr[i].first * 2 <= arr[0].first) {
			now += arr[i].first;
			ans.push_back(arr[i].second);
		}
	}

	if (now * 2 > sum) {
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] + 1 << " ";
		}
	} else {
		cout << 0;
	}
}