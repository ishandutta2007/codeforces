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

const int maxn = 85;
const int inf = 1e9 + 9;

int d[maxn][maxn];
vector<pair2<int>> d2[maxn][maxn];
int bads[maxn];
int bad[maxn];
int n, k;
int answer;

void check()
{
	int curans = 0;
	bads[k] = bads[0];
	for (int i = 0; i < k; i++)
	{
		int t = 0;
		int a = bads[i];
		int b = bads[i + 1];
		while (t < (int)d2[a][b].size() && bad[d2[a][b][t].se]) t++;
		if (t == (int)d2[a][b].size()) return;
		curans += d2[a][b][t].fi;
	}
	answer = min(answer, curans);
}

void go(int cur)
{
	if (cur == k)
	{
		check();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		bad[i]++;
		bads[cur] = i;
		go(cur + 1);
		bad[i]--;
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	k /= 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) scanf("%d", &d[i][j]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d2[i][j].clear();
			for (int k = 0; k < n; k++) if (k != i && k != j) d2[i][j].pb({d[i][k] + d[k][j], k});
			sort(all(d2[i][j]));
		}
	}
	answer = inf;
	bad[0] = 1;
	bads[0] = 0;
	go(1);
	cout << answer << endl;
    return 0;
}