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

//309810XU

#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

int P = 1000000000 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> cnt(60);
	for (int i = 0; i < n; i++) {
		int now = arr[i];
		for (int j = 0; j < 60; j++) {
			cnt[j] += now % 2;
			now /= 2;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val1 = 0;
		int now = arr[i];
		for (int j = 0; j < 60; j++) {
			int kek = (1LL << j) % P;
			if (now % 2 == 1) {
				int add = kek * cnt[j];
				add %= P;
				val1 += add;
				val1 %= P;
			}
			now /= 2;
		}
		now = arr[i];
		int val2 = 0;
		for (int j = 0; j < 60; j++) {
			int kek = (1LL << j) % P;
			if (now % 2 == 0) {
				int add = kek * cnt[j];
				add %= P;
				val2 += add;
				val2 %= P;
			} else {
				int add = kek * n;
				add %= P;
				val2 += add;
				val2 %= P;
			}
			now /= 2;
		}
		//cout << val1 << " " << val2 << endl;
		int need = val1 * val2;
		need %= P;
		ans += need;
		ans %= P;
	}
	cout << ans << endl;

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