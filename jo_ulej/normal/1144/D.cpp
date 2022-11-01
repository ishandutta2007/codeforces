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

struct Op
{
	int t, l, r;

	Op(int _t, int _l, int _r): t(_t), l(_l), r(_r)
	{
	}
};

int cnt[(int)1e6];
bool met[(int)1e6];
vector<int> a;
int n, god;

vector<Op> ops;

void rec(int i)
{
	met[i] = true;

	int left = (i == 0 ? -1 : a[i - 1]);
	int right = (i == n - 1 ? -1 : a[i + 1]);

	if(left != -1 && left != god)
	{
		if(left < god)
		{
			ops.emplace_back(1, i - 1, i);
		}
		else
		{
			ops.emplace_back(2, i - 1, i);
		}

		a[i - 1] = god;
		rec(i - 1);
	}

	if(right != -1 && right != god)
	{
		if(right < god)
		{
			ops.emplace_back(1, i + 1, i);
		}
		else
		{
			ops.emplace_back(2, i + 1, i);
		}

		a[i + 1] = god;
		rec(i + 1);
	}
}

void solve()
{
	cin >> n;
	a.resize(n);

	for(auto& el: a)
	{
		cin >> el;
		++cnt[el];
	}

	god = a.front();

	for(auto el: a)
		god = (cnt[el] > cnt[god] ? el : god);

	for(int att: {0, 1, 2})
		for(int i = 0; i < n; ++i)
			if(a[i] == god && !met[i])
				rec(i);

	cout << ops.size() << endl;

	for(auto op: ops)
		cout << op.t << " " << op.l + 1 << " " << op.r + 1 << "\n";
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}