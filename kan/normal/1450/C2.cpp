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

const int maxn = 305;

char s[maxn][maxn];
int cnt[2][3];
int n;
int id[2];

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		cnt[0][i] = 0;
		cnt[1][i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == 'X') cnt[1][(i + j) % 3] ++;
			if (s[i][j] == 'O') cnt[0][(i + j) % 3] ++;
		}
	}
	id[0] = min_element(cnt[0], cnt[0] + 3) - cnt[0];
	id[1] = min_element(cnt[1], cnt[1] + 3) - cnt[1];
	if (id[0] == id[1])
	{
		vector<pair<int, pair2<int>>> opts;
		for (int t = 0; t < 2; t++)
		{
			for (int j = 0; j < 3; j++) if (j != id[t])
			{
				opts.pb({cnt[t][j] - cnt[t][id[t]], {t, j}});
			}
		}
		sort(all(opts));
		id[opts[0].se.fi] = opts[0].se.se;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == 'X' && (i + j) % 3 == id[1]) s[i][j] = 'O';
			if (s[i][j] == 'O' && (i + j) % 3 == id[0]) s[i][j] = 'X';
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", s[i]);
	}
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