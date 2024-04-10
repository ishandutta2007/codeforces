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
	int n, m;
	cin >> n >> m;

	vector<int> arr1(n);
	vector<int> arr2(m);

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	int now = 0;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (now == m) {
			break;
		}

		if (arr1[i] <= arr2[now]) {
			ans++;
			now++;
		}
	}

	cout << ans;


}