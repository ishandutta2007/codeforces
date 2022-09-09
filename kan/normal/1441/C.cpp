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

const int maxn = 3005;
const int treesize = 1 << 12;

vector<pair<int, ll>> ops[2 * treesize];
vector<ll> ks;
int n, k;
int a[maxn][maxn];
ll answer = 0;
int len[maxn];
ll sum[maxn];

void apply(pair<int, ll> t)
{
	for (int i = k - t.fi; i >= 0; i--) ks[i + t.fi] = max(ks[i + t.fi], ks[i] + t.se);
}

void add(int cur, int cl, int cr, int l, int r, pair<int, ll> t)
{
	if (cl > r || cr < l) return;
	if (cl >= l && cr <= r)
	{
		ops[cur].pb(t);
		return;
	}
	int cm = (cl + cr) / 2;
	add(cur * 2, cl, cm, l, r, t);
	add(cur * 2 + 1, cm + 1, cr, l, r, t);
}

void go(int cur, int cl, int cr, int l, int r)
{
	if (cl > r) return;
	vector<ll> was = ks;
	for (auto t : ops[cur]) apply(t);
	
	if (cl == cr)
	{
		ll cursum = 0;
		for (int i = 0; i <= len[cl]; i++)
		{
			answer = max(answer, ks[k - i] + cursum);
			cursum += a[cl][i];
		}
	} else
	{
		int cm = (cl + cr) / 2;
		go(cur * 2, cl, cm, l, r);
		go(cur * 2 + 1, cm + 1, cr, l, r);
	}
	
	ks = was;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i =0 ; i < n; i++)
	{
		scanf("%d", &len[i]);
		for (int j =0 ; j < len[i]; j++)
		{
			if (j < k) scanf("%d", &a[i][j]);
			else scanf("%*d");
		}
		len[i] = min(len[i], k);
	}
	for (int i = 0; i < n; i++) sum[i] = accumulate(a[i], a[i] + len[i], 0LL);
	for (int i =0; i < n; i++)
	{
		add(1, 0, treesize - 1, 0, i - 1, {len[i], sum[i]});
		add(1, 0, treesize - 1, i + 1, n - 1, {len[i], sum[i]});
	}
	ks.resize(k + 1);
	go(1, 0, treesize - 1, 0, n - 1);
	cout << answer << endl;
    return 0;
}