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

const int maxn = 1005;
const ll inf = 2e18;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

char f[maxn][maxn];
ll ans[maxn][maxn];
int n, m, nq;
queue<pair2<int>> q;

inline bool isok(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main()
{
	scanf("%d%d%d", &n, &m, &nq);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", f[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans[i][j] = inf;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			bool foundsame = false;
			for (int d = 0; d < 4; d++)
			{
				int x = i + dx[d];
				int y = j + dy[d];
				if (isok(x, y) && f[x][y] == f[i][j]) foundsame = true;
			}
			if (foundsame)
			{
				ans[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		for (int d = 0; d  < 4; d++)
		{
			int x = cx + dx[d];
			int y = cy + dy[d];
			if (isok(x, y) && ans[x][y] > ans[cx][cy] + 1)
			{
				ans[x][y] = ans[cx][cy] + 1;
				q.push({x, y});
			}
		}
	}
	//for (int i = 0; i < n; i++)
	//{
		//for (int j = 0; j < m; j++) cout << ans[i][j] <<
	//}
	for (int q =0; q < nq; q++)
	{
		int x, y;
		ll t;
		scanf("%d%d%lld", &x, &y, &t);
		x--, y--;
		if (t <= ans[x][y]) printf("%c\n", f[x][y]);
		else
		{
			ll dd = (t - ans[x][y]) % 2;
			printf("%lld\n", (f[x][y] - '0' + dd) % 2);
		}
	}
    return 0;
}