#include <bits/stdc++.h>
 
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

ld dist(ld a, ld b, ld c, ld d)
{
	a -= c;
	b -= d;

	a *= a;
	b *= b;

	return sqrtl(a + b);
}

void solve()
{
	ld ax, ay, bx, by, tx, ty;
	cin >> ax >> ay >> bx >> by >> tx >> ty;

	int n;
	cin >> n;

	vector<ld> x(n), y(n);

	for(int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];

	ld answ = 0;

	for(int i = 0; i < n; ++i)
		answ += dist(tx, ty, x[i], y[i]);

	answ *= 2;

	vector<int> aa(n);
	iota(aa.begin(), aa.end(), 0);

	sort(aa.begin(), aa.end(), [&](int lhs, int rhs) {
		return -dist(tx, ty, x[lhs], y[lhs]) + dist(ax, ay, x[lhs], y[lhs]) < -dist(tx, ty, x[rhs], y[rhs]) + dist(ax, ay, x[rhs], y[rhs]);
	});

	vector<int> bb(n);
	iota(bb.begin(), bb.end(), 0);

	sort(bb.begin(), bb.end(), [&](int lhs, int rhs) {
		return -dist(tx, ty, x[lhs], y[lhs]) + dist(bx, by, x[lhs], y[lhs]) < -dist(tx, ty, x[rhs], y[rhs]) + dist(bx, by, x[rhs], y[rhs]);
	});

	ld dlt = 1e18;

	for(int idx1 = 0; idx1 <= 1 && idx1 < n; ++idx1)
	{
		for(int idx2 = 0; idx2 <= 1 && idx2 < n; ++idx2)
		{
			int i = aa[idx1], j = bb[idx2];

			if(i == j)
				continue;

			ld vala = -dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]);
			ld valb = -dist(tx, ty, x[j], y[j]) + dist(bx, by, x[j], y[j]);

			dlt = min(dlt, vala + valb);
		}
	}

	{
		int i = aa[0];

		ld val = -dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]);
		dlt = min(dlt, val);
	}

	{
		int j = bb[0];

		ld val = -dist(tx, ty, x[j], y[j]) + dist(bx, by, x[j], y[j]);
		dlt = min(dlt, val);
	}

	answ += dlt;

	cout << fixed << setprecision(12) << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}