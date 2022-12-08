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
	sort(a.begin(), a.end());
	vector<pair<int, int>> b;
	int l = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) l++;
		else {
			b.push_back({ a[i - 1], l });
			l = 1;
		}
	}
	b.push_back({ a[n - 1], l });
	n = b.size();
	l = b[n - 1].second;
	int x = n - 1, y = n - 1;
	int cx = n - 2, cy = n - 1;
	int cl = b[n - 1].second;
	for (int i = n - 2; i >= 0; i--) {
		//cout << l << " " << x << " " << y << " "  << b[i].first << " " << b[i].second << endl;
		//cout << cl << endl;
		if (b[i + 1].first - b[i].first > 1) {
			//cout << "lol\n";
			if (cl > l) {
				l = cl;
				x = cx + 1;
				y = cy;
			}
			cx = cy = i;
			cx--;
			cl = b[i].second;
		}
		else if (b[i].second == 1) {
			cl++;
			if (cl > l) {
				l = cl;
				x = cx;
				y = cy;
			}
			cx = cy = i;
			cx--;
			cl = 1;
		}
		else {
			//cout << "flex\n";
			if (cl > l) {
				l = cl;
				x = cx;
				y = cy;
			}
			cx--;
			cl += b[i].second;
		}
	}
	if (cl > l) {
		l = cl;
		x = cx + 1;
		y = cy;
	}
	//cout << cl << endl;
	cout << l << endl;
	//cout << x << " " << y << endl;
	deque<int> ans;
	for (int i = y; i >= x; i--) {
		ans.push_front(b[i].first);
		b[i].second--;
		for(int j = 0; j < b[i].second; j++) ans.push_back(b[i].first);
	}
	for (int i : ans) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}