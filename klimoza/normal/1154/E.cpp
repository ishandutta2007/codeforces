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

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	//n = 200000;	k = 1;
	vector<int> a(n);
	vector<pair<int, int>> p(n);
	vector<pair<int, int>> lr(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		//a[i] = i + 1;
		lr[i] = { i - 1, i + 1 };
		p[i] = { -a[i], i };
	}
	int cnt = 0;
	vector<int> used(n);
	sort(p.begin(), p.end());
	int ff = 0;
	int type = 1;
	//cout << p[n - 1].second << endl;
	int total = 0;
	while (cnt < n) {
		//cout << total << endl;
		while (used[p[ff].second]) {
			ff++;
			total++;
		}
		int ind = p[ff].second;
		used[ind] = type;
		cnt++;
		int l = 0;
		int f = lr[ind].second;
		int r = f;
		while (r != n && used[r]) {
			r = lr[r].second;
			total++;
			//cout << f << endl;
		}
		lr[ind].second = r;
		f = r;
		int h = 0;
		//cout << ind << endl;
		while (l < k && f != n) {
			//cout << f << " ez1" << endl;
			total++;
			l++;
			used[f] = type;
			cnt++;
			h = lr[f].second;
			while (h != n && used[h]) {
				h = lr[h].second;
				total++;
			}
			//cout << h << " ez2" << endl;
			lr[f].second = h;
			f = h;
		}
		l = 0;
		f = lr[ind].first;
		r = f;
		while (r != -1 && used[r]) {
			r = lr[r].first;
			total++;
			//cout << f << endl;
		}
		lr[ind].first = r;
		f = r;
		h = 0;
		while (l < k && f != -1) {
			l++;
			//if (used[f]) cout << f << " suka\n";
			//cout << f << " ez1" << endl;
			used[f] = type;
			cnt++;
			h = lr[f].first;
			while (h != -1 && used[h]) {
				//cout << h << endl;
				h = lr[h].first;
				total++;
			}
			total++;
			//cout << h << " ez2 " << (h != -1 ? used[h] : 1) << endl;
			lr[f].first = h;
			f = h;
		}
		if (type == 1) type = 2;
		else type = 1;
	}
	//cout << cnt << endl;
	for (int i : used) cout << i;
	cout << endl;
	//cout << total << endl;
	//cout << used[34] << endl;
	//system("pause");
	return 0;
}