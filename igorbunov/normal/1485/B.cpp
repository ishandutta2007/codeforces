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
	int n, q, k;
	cin >> n >> q >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	arr.push_back(k + 1);
	vector<int> pref(n);
	for (int i = 0; i < n; i++) {
		int now = arr[i + 1] - arr[i] - 1;
		if (i) {
			now += arr[i] - arr[i - 1] - 1;
			pref[i] += pref[i - 1];
		} else {
			now += arr[i] - 1;
		}
		pref[i] += now;
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int ans = pref[r];
		if (l) {
			ans -= pref[l - 1];
		}
		ans += k + 1 - arr[r + 1];
		if (l) {
			ans += arr[l - 1];
		}
		cout << ans << endl;
	}
}