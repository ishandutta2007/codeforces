#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)1e9 + 7;
const dbl eps = (dbl)1e-8;
const int maxn = (int)2e5 + 5;
const dbl pi = acos(-1);

int n, m, cl, ce;
ll v, l[maxn], e[maxn];

ll dist(pii st, pii en) {
	if (st.X == en.X)
		return abs(st.Y - en.Y);
	ll ans = linf;
	int li = lower_bound(l, l + cl, st.Y) - l;
	if (li < cl)
		ans = min(ans, abs(l[li] - st.Y) + abs(l[li] - en.Y) + abs(st.X - en.X));
	--li;
	if (li >= 0)
		ans = min(ans, abs(l[li] - st.Y) + abs(l[li] - en.Y) + abs(st.X - en.X));
	int ei = lower_bound(e, e + ce, st.Y) - e;
	if (ei < ce)
		ans = min(ans, abs(e[ei] - st.Y) + abs(e[ei] - en.Y) +
					abs(st.X - en.X) / v + (abs(st.X - en.X) % v > 0));
	--ei;
	if (ei >= 0)
		ans = min(ans, abs(e[ei] - st.Y) + abs(e[ei] - en.Y) +
					abs(st.X - en.X) / v + (abs(st.X - en.X) % v > 0));
	return ans;
}

int main() {
//	fin("t.in");
	sync;
	cin >> n >> m >> cl >> ce >> v;
	F(i, 0, cl) {
		cin >> l[i];
	}
	F(i, 0, ce) {
		cin >> e[i];
	}
	int numq;
	cin >> numq;
	F(i, 0, numq) {
		pii st, en;
		cin >> st.X >> st.Y >> en.X >> en.Y;
		cout << dist(st, en) << "\n";
	}
	return 0;
}