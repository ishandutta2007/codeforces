#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>
#include <deque>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;

//inline void operator delete (void *) {};

const int MAX_N = 1000;

int n, a, b, k, f;
unordered_map<string, int> mp;
int arr[MAX_N][MAX_N];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> a >> b >> k >> f;
	int last = -1;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		string s, t;
		cin >> s >> t;
		if (!mp.count(s)) {
			mp[s] = cnt++;
		}
		if (!mp.count(t)) {
			mp[t] = cnt++;
		}
		int val = 0;
		if (mp[s] != last) {
			val += a;
		}
		else {
			val += b;
		}
		last = mp[t];
		arr[min(mp[s], mp[t])][max(mp[s], mp[t])] += val;
	}
	vector<int> sums;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (arr[i][j] != 0) {
				sums.push_back(arr[i][j]);
			}
		}
	}
	sort(sums.begin(), sums.end());
	for (int i = 0; i < k; i++) {
		if (sums.size() > i && sums[sums.size() - 1 - i] >= f) {
			sums[sums.size() - 1 - i] = f;
		}
	}
	int ans = 0;
	for (int x : sums) {
		ans += x;
	}
	cout << ans << "\n";
	return 0;
}