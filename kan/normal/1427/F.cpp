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

const int maxn = 1205;

bitset<maxn> ans[3][maxn];
int g[maxn];
int ngroups = 0;
int c[maxn];
int n;
int cnt[maxn];

int go(int curc, int l, int r, bool take2 = false)
{
	assert(ans[curc][r][l]);
	if (l == r + 1) return -1;
	if (curc == 0) assert((r - l + 1) % 3 == 0);
	else assert((r - l + 1) % 3 == 1);
	for (int x = l; x <= r; x++)
	{
		if (curc == 0)
		{
			if (!take2 && ans[1][x - 1][l] && ans[1][r][x + 1])
			{
				int a = go(1, l, x - 1);
				int b = go(1, x + 1, r);
				g[a] = g[b] = g[x] = ngroups++;
				return -1;
			}
			if (ans[2][x - 1][l] && ans[2][r][x + 1])
			{
				int a = go(2, l, x - 1);
				int b = go(2, x + 1, r);
				g[a] = g[b] = g[x] = ngroups++;
				return -1;
			}
		} else
		{
			if (ans[0][x - 1][l] && ans[0][r][x + 1])
			{
				go(0, l, x - 1);
				go(0, x + 1, r);
				return x;
			}
		}
	}
	assert(false);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 6 * n; i++) c[i] = 2;
	for (int i = 0; i < 3 * n; i++)
	{
		int x;
		scanf("%d", &x);
		c[x] = 1;
	}
	n *= 6;
	ans[0][0][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		ans[c[i]][i][i] = 1;
		ans[0][i][i + 1] = 1;
		for (int j = i; j > 0; j--)
		{
			if (ans[c[j]][i][j + 1]) ans[0][i] |= ans[c[j]][j - 1];
			if (ans[0][i][j + 1]) ans[c[j]][i] |= ans[0][j - 1];
		}
		//for (int curc = 0; curc < 3; curc++)
		//{
			//for (int j = i + 1; j >= 0; j--) if (ans[curc][i][j] == 1)
			//{
				//cout << curc << ' ' << i << ' ' << j << ' ' << ans[curc][i][j] << endl;
			//}
		//}
	}
	go(0, 1, n, true);
	//for (int i = 1; i <= n; i++) cout << g[i] << ' ';
	//cout << endl;
	vector<int> all;
	for (int i = 1; i <= n; i++) all.pb(i);
	for (int it = 0; it < n / 3; it++)
	{
		int open = 0;
		for (auto t : all) cnt[g[t]] = 0;
		int x = -1;
		int y = -1;
		for (int i = 0; i + 2 < (int)all.size(); i++) 
		{
			if (c[all[i]] - 1 == it % 2 && g[all[i]] == g[all[i + 1]] && g[all[i]] == g[all[i + 2]])
			{
				if (it % 2 == 0 || open != 0 || (int)all.size() == 3) x = i;
				y = i;
			}
			cnt[g[all[i]]]++;
			if (cnt[g[all[i]]] == 3) open--;
			else if (cnt[g[all[i]]] == 1) open++;
		}
		if (x == -1) x = y;
		assert(x != -1);
		//cout << "take " << g[all[x]] << endl; 
		printf("%d %d %d\n", all[x], all[x + 1], all[x + 2]);
		rotate(all.begin() + x, all.begin() + x + 3, all.end());
		all.resize((int)all.size() - 3);
	}
    return 0;
}