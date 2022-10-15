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
#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const ll INF = 2 * 1000 * 1000 * 1000 + 5;
const int N = 100 * 1000 + 1;

//struct SegTree {
//	int n, N;
//	vector<pii> a;
//	SegTree(int nn) {
//		n = nn;
//		N = 4 * n + 10;
//		a.resize(N);
//	}
//	pii build(int v, int l, int r, const vector<int>& b) {
//		if (l == r) {
//			a[v] = pii(b[l], l);
//			return a[v];
//		}
//		int m = (l + r) / 2;
//		a[v] = min(build(2 * v, l, m, b), build(2 * v + 1, m + 1, r, b));
//		return a[v];
//	}
//	void build(const vector<int>& b) {
//		build(1, 0, n - 1, b);
//	}
//	pii get(int v, int tl, int tr, int l, int r) {
//		if ((tl >= l) && (tr <= r))
//			return a[v];
//		if ((tl > r) || (tr < l))
//			return pii(INF, 0);
//		int m = (tl + tr) / 2;
//		return min(get(2 * v, tl, m, l, r), get(2 * v + 1, m + 1, tr, l, r));
//	}
//	int get(int l, int r) {
//		return get(1, 0, n - 1, l, r).second;
//	}
//};


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int a[N], s[N], prMin[N], prMinLess[N];
	s[0] = 0;
	prMin[0] = 0;
	prMinLess[0] = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		s[i + 1] = s[i] + a[i];
		if (i) {
			if (a[i - 1] <= a[i])
				prMin[i] = prMin[i - 1];
			else
				prMin[i] = i;
			prMinLess[i] = prMin[i - 1];
			while((prMinLess[i] >= 0) && (a[prMinLess[i]] >= a[i])) {
				prMinLess[i] = prMinLess[prMinLess[i]];
			}
		}
	}
	//SegTree tr(n);
	//tr.build(a);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		int res = s[y + 1] - s[y - x];
		int id = prMin[y];
		while(id >= y - x) {
			res = min(res, s[y + 1] - s[id + 1] + a[id] * (x + 1 - y + id));
			id = prMinLess[id];
		}
		printf("%d\n", res);
		/*int id = tr.get(y - x, y);
		int res = s[y + 1] - s[id + 1] + a[id] * (x + 1 - y + id);
		cout << res << endl;*/
	}
	
	

    
    return 0;
}