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

const int MOD = 998244353;
 
inline int sum(int a, int b, int mod = MOD)
{
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

inline int sub(int a, int b, int mod = MOD)
{
	a -= b;
	if (a < 0) a += mod;
	return a;
}


inline int mul(int a, int b, int mod = MOD)
{
	return ((long long)a * b) % mod;
}

const int B = 30;
const int maxn = 200005;
int p2[maxn * 2];

struct td
{
	int trans, goes;
	
	int calc()
	{
		return sum(sub(p2[trans], 1), goes);
	}	
};

inline bool operator<(const td &a, const td &b)
{
	if (a.trans > B && b.trans <= B) return true;
	if (a.trans <= B && b.trans > B) return false;
	if (a.trans > B && b.trans > B) return (a.trans > b.trans || (a.trans == b.trans && a.goes > b.goes));
	return (1LL << a.trans) - 1 + a.goes > (1LL << b.trans) - 1 + b.goes;
}

vector<int> gr[2][maxn];
int n, m;
td d[maxn][B];
priority_queue<pair<td, pair2<int>>> q;

int main()
{
	p2[0] = 1;
	for (int i = 1; i < maxn * 2; i++) p2[i] = mul(2, p2[i - 1]);
	scanf("%d%d", &n, &m);
	for (int i =0 ; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[0][a].pb(b);
		gr[1][b].pb(a);
	}
	for (int i = 0; i < n; i++)
	{
		for (int t = 0; t < B; t++)
		{
			d[i][t] = {2 * maxn, 2 * maxn};
		}
	}
	d[0][0] = {0, 0};
	q.push({td({0, 0}), {0, 0}});
	while (!q.empty())
	{
		auto curd = q.top().first;
		auto [cur, curt] = q.top().se;
		q.pop();
		if (curd < d[cur][curt]) continue;
		//cout << cur << ' ' << curt << ' ' << curd.trans << ' ' << curd.goes << endl;
		auto nxtd = curd;
		nxtd.goes++;
		for (auto t : gr[curt % 2][cur])
		{
			if (d[t][curt] < nxtd)
			{
				d[t][curt] = nxtd;
				q.push({nxtd, {t, curt}});
			}
		}
		nxtd = curd;
		nxtd.trans++;
		int nt = curt + 1;
		if (nt >= B) nt -= 2;
		if (d[cur][nt] < nxtd)
		{
			d[cur][nt] = nxtd;
			q.push({nxtd, {cur, nt}});
		}
	}
	auto ans = d[n - 1][0];
	for (int i = 0; i < B; i++) if (ans < d[n - 1][i]) ans = d[n - 1][i];
	printf("%d\n", ans.calc());
    return 0;
}