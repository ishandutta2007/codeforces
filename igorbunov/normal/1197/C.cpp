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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<pair<int, int>> dist(n - 1);

	for (int i = 0; i < n - 1; i++) {
		dist[i].first = arr[i + 1] - arr[i];
		dist[i].second = i;
	}

	sort(dist.rbegin(), dist.rend());
	int l = 0;
	int ans = 0;
	for (int j = 0; j < k - 1; j++) {
		int a = dist[j].second;
		ans += arr[a] - arr[l];
		l = a + 1;
	}
	ans += arr.back() - arr[l];

	cout << ans;

	}