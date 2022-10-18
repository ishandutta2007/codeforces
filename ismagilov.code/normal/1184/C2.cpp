#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

#define ft first
#define sc second
#define int ll
#define pb push_back

using namespace std;
typedef long long ll;

struct point {
	int x, y;
	bool operator < (const point& b) const {
		if(x < b.x)
			return 1;
		if(x > b.x) 
			return 0;
		return (y < b.y);
	}
};

using namespace std;

int inf = 2e6 + 100;
int maxt = 4e6 + 100;
int N = 1;
vector<int> tree;
vector<int> push;
void upd(int v, int vl, int vr, int l, int r, int val) {
	//cout << v << " " <<  vl << " " << vr << " " << l << " " << r << endl;
	if(vr <= l || r <= vl) 
		return;
	if(l <= vl && vr <= r) {
		tree[v] += val;
		push[v] += val;
		return;
	}
	if(push[v] != 0) {
		tree[v * 2] += push[v];
		push[v * 2] += push[v];
		tree[v * 2 + 1] += push[v];
		push[v * 2 + 1] += push[v];
		push[v] = 0;
	}
	int m = (vl + vr) / 2;
	upd(v * 2, vl, m, l, r, val);
	upd(v * 2 + 1, m, vr, l, r, val);
	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	return;
}


signed main() {
	/*#ifndef ONLINE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif*/
	int n, r;
	cin >> n >> r;
	r = 2 * r;
	vector<point> pt(n);
	for (int i = 0; i < n; i++) {
		cin >> pt[i].x >> pt[i].y;
		int x = pt[i].x - pt[i].y;
		int y = pt[i].x + pt[i].y;
		pt[i].x = x, pt[i].y = y;
		pt[i].x += inf;
		pt[i].y += inf;
	}
	while(N < maxt) 
		N *= 2;
	tree = vector<int> (2 * N, 0);
	push = vector<int> (2 * N, 0);
	sort(pt.begin(), pt.end());
	int u = 0;
	int i = 0;
	int ans = 0;
	while(i < n) {
		int lst = i;
		vector<point> now;
		while(lst < n && pt[lst].x == pt[i].x) {
			now.pb(pt[lst]);
			lst++;
		}
		while(u < n && pt[u].x <= pt[i].x + r) {
			upd(1, 0, N, pt[u].y, min(N, pt[u].y + r + 1), 1);
			u++;
		}
		ans = max(ans, tree[1]);
		for (auto a : now) {
			upd(1, 0, N, a.y, min(N, a.y + r + 1), -1);
		}
		i = lst;
	}
	cout << ans << endl;
}