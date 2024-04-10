#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 100005;

vector<int> gr[maxn];
vector<int> path;
int d[maxn], dleft[maxn], dright[maxn];
bool canrev[maxn];
int n, m;
bool inpath[maxn];
int st, fn;

bool findpath(int cur, int pr, int target)
{
	if (cur == target)
	{
		path.pb(cur);
		return true;
	}
	for (auto t : gr[cur]) if (t != pr)
	{
		if (findpath(t, cur, target))
		{
			path.pb(cur);
			return true;
		}
	}
	return false;
}

pair<int, bool> getmaxd(int cur, int pr)
{
	int maxd = 0;
	bool canrev = false;
	for (auto t : gr[cur]) if (t != pr && !inpath[t])
	{
		auto ret = getmaxd(t, cur);
		ret.fi++;
		if (maxd >= m - 1 && ret.fi >= m - 1) canrev = true;
		canrev |= ret.se;
		maxd = max(maxd, ret.fi);
	}
	return {maxd, canrev};
}

void solve()
{
	scanf("%d%d%d", &n, &st, &fn);
	st--, fn--;
	for (int i = 0; i < n; i++) gr[i].clear();
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	path.clear();
	assert(findpath(st, -1, fn));
	reverse(all(path));
	for (int i = 0; i < n; i++) inpath[i] = false;
	for (auto t : path) inpath[t] = true;
	m = (int)path.size();
	for (int i = 0; i < m; i++)
	{
		auto ret = getmaxd(path[i], -1);
		d[i] = ret.fi;
		canrev[i] = ret.se;
	}
	dleft[0] = min(d[0], m - 2);
	for (int i = 1; i < m; i++)
	{
		dleft[i] = max(dleft[i - 1], min(d[i] - i, m - 1 - i - 1));
	}
	dright[m - 1] = min(d[m - 1], m - 2);
	for (int i = m - 2; i >= 0; i--)
	{
		dright[i] = max(dright[i + 1], min(d[i] - (m - 1 - i), i - 1));
	}
	int maxleft = 0;
	int maxright = 0;
	while (true)
	{
		int mxr = max(maxright, dright[m - 1 - maxleft]);
		int mxl = max(maxleft, dleft[maxright]);
		if (mxr == maxright && mxl == maxleft) break;
		maxleft = mxl;
		maxright = mxr;
	}
	bool ok = false;
	for (int i = 0; i < m; i++)
	{
		if ((maxright >= i || maxleft >= (m - 1 - i)) && canrev[i]) ok = true;
		if (maxright >= i && maxleft >= (m - 1 - i) && d[i] >= m - 1) ok = true;
	}
	printf("%s\n", (ok ? "Yes" : "No"));
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		solve();
	}
    return 0;
}