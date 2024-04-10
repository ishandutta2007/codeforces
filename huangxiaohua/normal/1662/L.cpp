#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#define sz(v) ((int)(v).size())
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
template <typename T> bool chkmin (T &x, T y) {return y < x ? x = y, 1 : 0;}
template <typename T> bool chkmax (T &x, T y) {return y > x ? x = y, 1 : 0;}

const int N = 1e6 + 5;

int n, v;
int t[N], x[N];

vector <pll> a;
bool cmp (pll a, pll b) {
	if (a.se != b.se) return a.se > b.se;
	return a.fi > b.fi;
}

vector <ll> pos;
int getid (ll curpos) {
	return lower_bound(pos.begin(), pos.end(), curpos) - pos.begin() + 1;
}
struct BIT {
	int n;
	int c[N];
	int lowbit (int x) {return x & (-x);}
	void init (int _n) {n = _n; for (int i = 0;i <= n;++i) c[i] = 0;}
	void update (int i, int x) {while (i) {chkmax(c[i], x); i -= lowbit(i);}}
	int query (int i) {int ret = 0; while (i <= n) {chkmax(ret, c[i]); i += lowbit(i);} return ret;}
} bit;

int main () {
	scanf("%d%d", &n, &v);
	for (int i = 1;i <= n;++i) {
		scanf("%d", &t[i]);
	}
	for (int i = 1;i <= n;++i) {
		scanf("%d", &x[i]);
	}
	for (int i = 1;i <= n;++i) {
		ll curx = 1ll * t[i] * v + x[i];
		ll cury = 1ll * t[i] * v - x[i];
		if ((curx < 0) || (cury < 0)) continue;
		a.push_back({curx, cury});
		pos.push_back(curx);
	}
	sort(a.begin(), a.end(), cmp);
	sort(pos.begin(), pos.end());
	
	bit.init(sz(a) + 5);
	for (auto [x, y] : a) {
		// cout << x << ' ' << y << ' ' << getid(x) << endl;
		x = getid(x);
		int curdp = bit.query(x) + 1;
		bit.update(x, curdp);
	}
	printf("%d\n", bit.query(1));
}