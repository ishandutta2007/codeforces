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

//#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

vector<int> cnt(2000000);

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> kek;
	vector<int> kek1;
	for (int _ = 0; _ < n; _++) {
		int val = arr[_];
		int real = 1;
		for (int i = 2; i * i <= val; i++) {
			int cnt = 0;
			while (val % i == 0) {
				cnt++;
				val /= i;
			}
			if (cnt % 2 == 1) {
				real *= i;
			}
		}
		if (val != 1)  {
			real *= val;
		}
		//cout << "R " << real << endl;
		cnt[real]++;
		kek.push_back(real);
		kek1.push_back(real);
	}

	sort(kek.begin(), kek.end());
    auto it = unique(kek.begin(), kek.end());
    kek.resize(it - kek.begin());
	int ans1 = 0;
	for (auto u : kek) {
		ans1 = max(ans1, cnt[u]);
	}
	int ans2 = 0;
	for (auto u: kek) {
		if (cnt[u] % 2 == 0 || u == 1) {
			ans2 += cnt[u];
		}
	}
	for (auto u: kek) {
		if (cnt[u] % 2 == 1) {
			ans2 = max(ans2, cnt[u]);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long w;
		cin >> w;
		if (w == 0LL) {
			cout << ans1 << endl;
		} else {
			cout << ans2 << endl;
		}
	}
	for (auto u: kek1) {
		cnt[u]--;
	}
	kek.clear();
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