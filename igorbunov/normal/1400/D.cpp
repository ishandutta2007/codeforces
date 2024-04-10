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


//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<vector<int>> kek(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				kek[i].push_back(j);
			}
		}
	}
	vector<int> inds(n, -1);
	int ans = 0LL;
	for (int l = 0; l < n; l++) {
		int cnt = 0;
		for (int r = l + 1; r < n; r++) {
            if (arr[l] == arr[r]) {
                ans += cnt;
            }
			cnt += (inds[r] + 1);
		}
		for (int r = l + 1; r < n; r++) {
			while (inds[r] + 1 < kek[r].size() && kek[r][inds[r] + 1] <= l) {
				inds[r]++;
			}
		}
	}
	cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}