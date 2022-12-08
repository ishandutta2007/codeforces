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
	vector<int> b(n);
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		s.insert(b[i]);
	}
	int t1, t2;
	for (int i = 0; i < n; i++) {
		t1 = (a[i] + *s.begin()) % n;
		auto u = s.lower_bound(n - a[i]);
		if (u == s.end()) t2 = INFi;
		else t2 = (a[i] + *u) % n;
		//cout << t1 << " " << t2 << endl;
		if (t1 < t2) {
			cout << t1 << " ";
			s.erase(s.begin());
		}
		else {
			cout << t2 << " ";
			s.erase(u);
		}
	}
	//system("pause");
	return 0;
}