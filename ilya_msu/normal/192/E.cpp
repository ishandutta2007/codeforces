#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
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

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;
using std::map;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  

vector<vector<pii> > g;
vector<int> order;
int ind = 0;
vector<int> height;
vector<int> first;
vector<int> lcaSegmentTree;
vector<int> ans, res;

void dfs(int pos, int pr) {
	if (pr != -1)
		height[pos] = height[pr] + 1;
	order[ind] = pos;
	first[pos] = ind;
	++ind;
	for(int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i].first;
		if (to == pr)
			continue;
		dfs(to, pos);
		order[ind] = pos;
		++ind;
	}
	return;
}

void build(int v, int l, int r) {
	if (l == r)
		lcaSegmentTree[v] = order[l];
	else {
		int m = (l + r) / 2;
		build(2 * v, l, m);
		build(2 * v + 1, m + 1, r);
		if (height[lcaSegmentTree[2 * v]] < height[lcaSegmentTree[2 * v + 1]])
			lcaSegmentTree[v] = lcaSegmentTree[2 * v];
		else
			lcaSegmentTree[v] = lcaSegmentTree[2 * v + 1];
	}
}

int getLca(int v, int tl, int tr, int l, int r) {
	if ((l == tl) && (r == tr))
		return lcaSegmentTree[v];
	int tm = (tl + tr) >> 1;
	if (r <= tm)
		return getLca(2 * v, tl, tm, l, r);
	if (l > tm) 
		return getLca(2 * v + 1, tm  + 1, tr, l, r);
	int al = getLca(2 * v, tl, tm, l, tm);
	int ar = getLca(2 * v + 1, tm + 1, tr, tm + 1, r);
	if (height[al] < height[ar])
		return al;
	else
		return ar;
}

int dfs2(int pos, int pr) {
	int sum = ans[pos];
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i].first;
		if (to == pr)
			continue;
		int x = dfs2(to, pos);
		res[g[pos][i].second] = x;
		sum += x;
	}
	return sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	g.resize(n);
	height.assign(n, 0);
	first.resize(n);
	order.resize(2 * n - 1);
	int m = 2 * n - 1;
	lcaSegmentTree.assign(4 * m + 1, 0);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(make_pair(b, i));
		g[b].push_back(make_pair(a, i));
	}
	int q;
	cin >> q;
	vector<pii> query(q);
	for (int i = 0; i < q; ++i) {
		cin >> query[i].first >> query[i].second;
		--query[i].first;
		--query[i].second;
	}
	dfs(0, -1);
	build(1, 0, m - 1);
	ans.assign(n, 0);
	for (int i = 0; i < q; ++i) {
		int l = first[query[i].first];
		int r = first[query[i].second];
		++ans[query[i].first];
		++ans[query[i].second];
		if (l > r)
			swap(l, r);
		int lca = getLca(1, 0, m - 1, l, r);
		ans[lca] -= 2;
	}
	res.assign(n - 1, 0);
	dfs2(0, -1);
	for (int i = 0; i < n - 1; ++i)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}