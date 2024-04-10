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

const int maxn = 105;

const int inf = 1e8;

int ans[maxn][maxn][20];
int n, m, k;
char s[maxn][maxn];

inline void upd(int &a, int b)
{
	a = max(a, b);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	k++;
	for (int i =0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int t = 0; t < k; t++) ans[i][j][t] = -inf;
		}
	}
	for (int i =0 ; i < m; i++) ans[n - 1][i][(s[n - 1][i] - '0') % k] = (s[n - 1][i] - '0');
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j =0 ; j < m; j++)
		{
			int x = s[i][j] - '0';
			for (int t =0 ; t < k; t++)
			{
				if (j + 1 < m) upd(ans[i][j][(t + x) % k], ans[i + 1][j + 1][t] + x);
				if (j > 0) upd(ans[i][j][(t + x) % k], ans[i + 1][j - 1][t] + x);
			}
		}
	}
	int answer = -inf;
	int from = -1;
	for (int i = 0; i < m; i++) if (ans[0][i][0] > answer)
	{
		answer = ans[0][i][0];
		from = i;
	}
	if (answer < 0)
	{
		cout << -1 << endl;
		return 0;
	}
	string res;
	int cr = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int x = s[i][from] - '0';
		int tr = cr;
		cr = ((cr - x) % k + k) % k;
		if (from > 0 && ans[i][from][tr] == ans[i + 1][from - 1][cr] + x)
		{
			res.pb('R');
			from--;
		} else
		{
			res.pb('L');
			from++;
		}
	}
	reverse(all(res));
	cout << answer << endl << from + 1 << endl << res << endl;
	
    return 0;
}