#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <random>
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

#define s second
#define f first
#define push_back emplace_back


int gcd(int x, int y) {
	if (!y) {
		return x;
	}
	return gcd(y, x % y);
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1) {
		if (arr[0] == 1) {
			cout << "1 1\n";
		} else {
			cout << "0\n";
		}
		return;
	}
	set<int> kek;
	vector<int> next(n);
	vector<int> prev(n);
	for (int i = 0; i < n; i++) {
		next[i] = (i + 1) % n;
		prev[(i + 1) % n] = i;
	}
	for (int i = 0; i < n; i++) {
		if (gcd(arr[i], arr[(i + 1) % n]) == 1) {
			kek.insert(i);
			kek.insert(i + n);
		}
	}
	vector<int> ans;
	int last_pos = -1;
	int cnt = 0;
	vector<bool> was(n);
	while (kek.size() != 0 && cnt != 3) {
		//cnt++;
		int p = *(kek.lower_bound(last_pos));
		if (p >= n) {
			p -= n;
		}
		kek.erase(p);
		kek.erase(p + n);
		int now_del = next[p];
		int p1 = next[now_del];
		//cout << p << " " << now_del << " " << p1 << endl;
		if (kek.find(now_del) != kek.end()) {
			kek.erase(now_del);
			kek.erase(now_del + n);
		}
		if (!was[now_del]) {
			ans.push_back(now_del + 1);
		} else {
			break;
		}
		was[now_del] = true;
		if (p == p1) {
			if (arr[p] == 1) {
				ans.push_back(p + 1);
			}
			break;
		}
		prev[p1] = p;
		next[p] = p1;
		if (gcd(arr[p], arr[p1]) == 1) {
			kek.insert(p);
			kek.insert(p + n);
		}
		last_pos = now_del;
	}
	cout << ans.size() << " ";
	for (auto val: ans) {
		cout << val << " ";
	}
	cout  << endl;
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