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

const int MAX_N = (int)1e5 + 6;
int block_size, n, m, a[MAX_N];

struct Query
{
	int l, r, idx;

	bool operator<(const Query& other) const
	{
		if(l / block_size != other.l / block_size)
			return l < other.l;

		return r < other.r;
	}
};

int L = 0, R = -1;
int cnt[MAX_N], b[MAX_N], answ = 0;

inline void incR()
{
	++R;

	if(cnt[a[R]] == b[R])
		--answ;

	++cnt[a[R]];

	if(cnt[a[R]] == b[R])
		++answ;
}

inline void decL()
{
	--L;

	if(cnt[a[L]] == b[L])
		--answ;

	++cnt[a[L]];

	if(cnt[a[L]] == b[L])
		++answ;
}

inline void incL()
{
	if(cnt[a[L]] == b[L])
		--answ;

	--cnt[a[L]];

	if(cnt[a[L]] == b[L])
		++answ;

	++L;
}

inline void decR()
{
	if(cnt[a[R]] == b[R])
		--answ;

	--cnt[a[R]];

	if(cnt[a[R]] == b[R])
		++answ;

	--R;
}

inline int getans()
{
	return answ;
}

void solve()
{
	cin >> n >> m;
	block_size = sqrt(n) + 1;
	vector<Query> queries(m);

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 0; i < m; ++i)
	{
		cin >> queries[i].l >> queries[i].r;
		--queries[i].l, --queries[i].r;
		queries[i].idx = i;
	}

	sort(queries.begin(), queries.end());
	map<int, int> mp;

	for(int i = 0; i < n; ++i)
	{
		if(mp.find(a[i]) == mp.end())
			mp.insert({a[i], mp.size()});

		b[i] = a[i];
		a[i] = mp[a[i]];
	}

	vector<int> ans(m);

	for(auto q: queries)
	{
		while(R < q.r)
			incR();

		while(L > q.l)
			decL();

		while(R > q.r)
			decR();

		while(L < q.l)
			incL();

		ans[q.idx] = getans();
	}

	for(auto el: ans)
		cout << el << "\n";
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}