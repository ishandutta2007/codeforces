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

const int MAX_N = (int)1e5 + 777;

int x[MAX_N], n, k;
int fst[MAX_N];
vector<int> tree[4 * MAX_N];

vector<int> mrg(const vector<int>& lhs, const vector<int>& rhs)
{
	int n1 = lhs.size(), n2 = rhs.size();
	int i = 0, j = 0;

	vector<int> ret;

	while(i < n1 && j < n2)
	{
		if(lhs[i] < rhs[j])
		{
			ret.push_back(lhs[i]);
			++i;
		}
		else
		{
			ret.push_back(rhs[j]);
			++j;
		}
	}

	while(i < n1)
	{
		ret.push_back(lhs[i]);
		++i;
	}

	while(j < n2)
	{
		ret.push_back(rhs[j]);
		++j;
	}

	return ret;
}

void build(int v, int tl, int tr)
{
	if(tl == tr)
	{
		tree[v].push_back(x[tl]);
	}
	else
	{
		int tm = (tl + tr) / 2;

		build(2 * v + 1, tl, tm);
		build(2 * v + 2, tm + 1, tr);

		tree[v] = mrg(tree[2 * v + 1], tree[2 * v + 2]);
	}
}

bool get(int v, int tl, int tr, int l, int r, int value)
{
	if(tl == l && tr == r)
	{
		auto it = lower_bound(tree[v].begin(), tree[v].end(), value);

		if(it == tree[v].end())
			return false;

		return (*it == value);
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(r <= tm)
			return get(2 * v + 1, tl, tm, l, r, value);

		if(l >= tm + 1)
			return get(2 * v + 2, tm + 1, tr, l, r, value);

		bool fl1 = get(2 * v + 1, tl, tm, l, tm, value);

		if(fl1)
			return true;

		return get(2 * v + 2, tm + 1, tr, tm + 1, r, value);
	}
}

bool has(int l, int r, int value)
{
	/*for(int j = l; j <= r; ++j)
		if(x[j] == value)
			return true;

	return false;*/

	if(l > r)
		return false;

	return get(0, 0, k - 1, l, r, value);
}

void solve()
{
	cin >> n >> k;

	for(int i = 0; i < k; ++i)
		cin >> x[i];

	for(int i = 0; i < MAX_N; ++i)
		fst[i] = k;

	for(int i = 0; i < k; ++i)
		if(fst[x[i]] == k)
			fst[x[i]] = i;

	build(0, 0, k - 1);

	ll answ = 0;

	for(int a = 1; a <= n; ++a)
	{
		int i = fst[a];

		for(int b = a - 1; b <= a + 1; ++b)
			if(!has(i, k - 1, b) && b >= 1 && b <= n)
				++answ;
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}