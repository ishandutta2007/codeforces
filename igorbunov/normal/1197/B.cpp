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
	vector<int> arr(n);
	vector<int> arr1(n);
	int maxn = -1;
	int ind;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr1[i] = arr[i];
		if (arr[i] > maxn) {
			maxn = arr[i];
			ind = i;
		}
	}

	sort(arr1.begin(), arr1.end());
	int l = ind;
	int r = ind + 1;
	int now = n - 1;

	while (now >= 0) {
		int val = arr1[now];
		if (l >= 0 && arr[l] == val) {
			l--;
			now--;
			continue;
		}

		if (r < n && arr[r] == val) {
			r++;
			now--;
			continue;
		}

		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}