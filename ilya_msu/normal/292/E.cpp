#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
const int N = 1000 * 100 + 10;

struct SegTree {
	int n;
	vector<int> t;
    SegTree(int nn) {
		n = nn;
		t.assign(4 * n, 0);		
	}
	int query(int v, int tl, int tr, int q) {
		if (t[v] != -1)
			return t[v];
		int tm = (tl + tr) / 2;
		if (q <= tm)
			return query(2 * v, tl, tm, q);
		else
			return query(2 * v + 1, tm + 1, tr, q);
	}
	void update(int v, int tl, int tr, int posl, int posr, int val) {
		posl = max(tl, posl);
		posr = min(tr, posr);
		if (posl > posr)
			return;
		if ((tl == posl) && (tr == posr)) {
			t[v] = val;
			return;
		}
		int tm = (tl + tr) / 2;
		if (t[v] != -1) {
			update(v * 2, tl, tm, tl, tm, t[v]);
			update(v * 2 + 1, tm + 1, tr, tm + 1, tr, t[v]);
			t[v] = -1;
		}
		update(v * 2, tl, tm, posl, posr, val);
		update(v * 2 + 1, tm + 1, tr, posl, posr, val);
	}
};

struct qu {
	int x, y, k;
};

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	SegTree tree(n);
	vector<qu> q;
	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			qu qq;
			cin >> qq.x >> qq.y >> qq.k;
			--qq.x;
			--qq.y;
			q.push_back(qq);
			tree.update(1, 0, n - 1, qq.y, qq.y + qq.k - 1, q.size());
		}
		else {
			int x;
			cin >> x;
			--x;
			int lastq = tree.query(1, 0, n - 1, x);
			if (lastq == 0)
				printf("%d\n", b[x]);
			else {
				qu qq = q[lastq - 1];
				printf("%d\n", a[x + qq.x - qq.y]);
			}
		}
	}
	return 0;
}