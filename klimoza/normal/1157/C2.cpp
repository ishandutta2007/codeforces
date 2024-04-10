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

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<char> ans;
	int l = 0, r = n - 1;
	int last = 0;
	while (l <= r) {
		if (a[l] <= last && a[r] <= last) break;
		if (a[l] != a[r]) {
			if (a[l] > last && a[r] <= last) {
				ans.push_back('L');
				last = a[l];
				l++;
			}
			else if (a[r] > last && a[l] <= last) {
				ans.push_back('R');
				last = a[r];
				r--;
			} else if (a[l] < a[r]) {
				ans.push_back('L');
				last = a[l];
				l++;
			}
			else {
				ans.push_back('R');
				last = a[r];
				r--;
			}
		}
		else {
			//cout << l << " " << r << " " << ans.size() << endl;
			int f1 = 1;
			int f2 = 1;
			for (int i = l + 1; i < r; i++) {
				if (a[i] > a[i - 1]) f1++;
				else break;
			}
			for (int i = r - 1; i > l; i--) {
				if (a[i] > a[i + 1]) f2++;
				else break;
			}
			//cout << f1 << " " << f2 << endl;
			if (f1 > f2) {
				while (f1--) ans.push_back('L');
			}else{
				while (f2--) ans.push_back('R');
			}
			break;
		}
	}
	cout << ans.size() << endl;
	for (char c : ans) cout << c;
	cout << endl;
	//system("pause");
	return 0;
}