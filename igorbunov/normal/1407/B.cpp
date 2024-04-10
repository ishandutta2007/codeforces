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

int gcd(int a, int b) {
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1) {
		cout << arr[0] << endl;
		return;
	}
	int i1 = -1;
	int i2 = -1;
	int now1 = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1; j++) {
			if (gcd(arr[i], arr[i]) > now1) {
				now1 = max(now1, gcd(arr[i], arr[i]));
				i1 = i;
			}
		}
	}
	vector<bool> used(n);
	vector<int> ans(n);
	ans[0] = arr[i1];
	used[i1] = true;
	int ind = 1;
	int now = now1;
	while (ind != n) {
		int i3 = -1;
		int now2 = -1;
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				if (gcd(now, arr[i]) > now2) {
					now2 = gcd(now, arr[i]);
					i3 = i;
				}
			}
		}
		ans[ind] = arr[i3];
		used[i3] = true;
		ind++;
		now = now2;
	}
	for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
	}
	cout << endl;
}
signed main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}