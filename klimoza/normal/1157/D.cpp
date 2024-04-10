#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")	
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;
typedef vector<vector<int>> matrix;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << "YES\n";
		cout << n << endl;
		return 0;
	}
	if (k == 2) {
		if (n <= 2) {
			cout << "NO\n";
			return 0;
		}
		else {
			if (n % 2 == 1) {
				cout << "YES\n";
				cout << n / 2 << " " << n / 2 + 1 << endl;
			}
			else {
				if (n == 4) {
					cout << "NO\n";
					return 0;
				}
				cout << "YES\n";
				cout << n / 2 - 1 << " " << n / 2 + 1 << endl;
			}
			return 0;
		}
	}
	vector<int> ans(k);
	ll cur = 0;
	for (int i = 0; i < k; i++) {
		ans[i] = i + 1;
		cur += i + 1;
	}
	if (cur > n) {
		cout << "NO\n";
		return 0;
	}
	int f = (n - cur) / k;
	for (int i = 0; i < k; i++) {
		ans[i] += f;
		cur += f;
	}
	if (2 * ans[k - 2] - ans[k - 1] >= n - cur) {
		ans[k - 1] += n - cur;
	}
	else {
		if (ans[k - 3] == 1) {
			cout << "NO\n";
			return 0;
		}
		else {
			ans[k - 2]++;
			cur++;
			ans[k - 1] += n - cur;
		}
	}
	cout << "YES\n";
	for (int i : ans) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}