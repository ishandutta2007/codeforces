#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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
#include<cassert>
#include<functional>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000000;


struct SegTree {
	int n;
	vector<int> a;
	int build(const vector<int>& b, int v, int l, int r) {
		//cerr << l << "\t" << r << "\n";
		if (l == r) {
			return a[v] = b[l];
		}
		return a[v] = min(build(b, 2 * v, l, (l + r) / 2), build(b, 2 * v + 1, (l + r) / 2 + 1, r));
	}
	SegTree(const vector<int>& b) {
		n = b.size();
		a.resize(4 * n + 10);
		build(b, 1, 0, n - 1);
	}
	int get(int v, int tl, int tr, int l, int r) {
		if ((l <= tl) && (r >= tr))
			return a[v];
		if ((l > tr) || (r < tl))
			return INF;
		return min(get(2 * v, tl, (tl + tr) / 2, l, r), get(2 * v + 1, (tl + tr) / 2 + 1, tr, l, r));
	}
	int get(int l, int r) {
		return get(1, 0, n - 1, l, r);
	}

};

int ceil(const vector<int>& a, int x) {
	int up = a.size(), down = -1;
	while (up - down > 1) {
		int mid = (up + down) / 2;
		if (x <= a[mid])
			up = mid;
		else
			down = mid;
	}
	if (up == a.size())
		return -1;
	return up;
}

int floor(const vector<int>& a, int x) {
	int up = a.size(), down = -1;
	while (up - down > 1) {
		int mid = (up + down) / 2;
		if (x >= a[mid])
			down = mid;
		else
			up = mid;
	}
	return down;
}

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	map<int, int> prev;
	vector<pii> seg;
	for (int i = 0; i < n; ++i) {
		if (prev.find(a[i]) != prev.end())
			seg.push_back(pii(prev[a[i]], i));
		prev[a[i]] = i;
	}
	sort(seg.begin(), seg.end());
	if (seg.empty())
		seg.push_back(pii(-1, 0));
	vector<int> ok(seg.size(), 1);
	int rm = INF;
	
	for (int i = 0; i < seg.size(); ++i) {
		int j = seg.size() - i - 1;
		if (seg[j].second >= rm)
			ok[j] = 0;
		rm = min(rm, seg[j].second);		
	}

	vector<int> left, right, val;
	for (int i = 0; i < ok.size(); ++i)
		if (ok[i]) {
			left.push_back(seg[i].first);
			right.push_back(seg[i].second);
			val.push_back(seg[i].second - seg[i].first);
		}
	SegTree tr(val);
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		--l, --r;
		int li = ceil(left, l);
		int ri = floor(right, r);
		if ((li == -1) || (ri == -1) || (ri < li))
			printf("-1\n");
		else
			printf("%d\n", tr.get(li, ri));
	}
}

//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	/*int n = 500000;
	cout << n << " " << n << endl;
	for (int i = 0; i < n; ++i) {
		cout << rand() << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		int l = rand() + 1;
		int r = l + rand();
		cout << l << " " << r << endl;
	}*/

#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}