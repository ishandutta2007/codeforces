
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <random>
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = 1e9 + 7;
mt19937 gen;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<ll> a(n);
	const int PW = 60;
	ll cur = 0;
	vector<vector<ll>> ls(PW);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int l = -1;
		for (int j = 0; j < PW; j++) {
			if (a[i] & (1ll << j)) {
				l = j;
			}
		}
		ls[l].push_back(a[i]);
		cur ^= a[i];
	}

	vector<ll> ans;

	for (int i = 0; i < n; i++) {
		int whr = -1;
		for (int j = 0; j < PW; j++) {
			if (ls[j].size() && (cur & (1ll << j)) && whr == -1) {
				whr = j;
			}
		}
		if (whr == -1) {
			cout << "No\n";
			return 0;
		}
		ans.push_back(ls[whr].back());
		cur ^= ls[whr].back();
		ls[whr].pop_back();
	}
	cout << "Yes\n";
	reverse(ans.begin(), ans.end());
	for (ll x : ans) {
		cout << x << ' ';
	}

    return 0;
}