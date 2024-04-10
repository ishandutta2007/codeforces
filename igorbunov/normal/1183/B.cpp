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

using namespace std;

signed main() {
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int ans = arr[0] + k;
		if (arr.back() - ans <= k) {
			cout << ans;
		} else {
			cout << -1;
		}
		cout << endl;
	}
}