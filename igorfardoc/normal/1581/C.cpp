#include<bits/stdc++.h>
#define LOG 10
#define N 400
using namespace std;
typedef long long ll;
int p[1000];
int table[N][LOG][N];
string a[N];
int n, m;
int pref[N + 1][N + 1];
int dp[N][N];
int res;

inline void build_pref()
{
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(i == 0 || j == 0)
			{
				pref[i][j] = 0;
				continue;
			}
			pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + (a[i - 1][j - 1] == '1');
		}
	}
}
inline void build_dp()
{
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j < m; j++)
		{
			if(i == n - 1)
			{
				dp[i][j] = n;
				continue;
			}
			if(a[i + 1][j] == '1')
			{
				dp[i][j] = i + 1;
				continue;
			}
			dp[i][j] = dp[i + 1][j];
		}
	}
}
inline void build_table()
{
	for(int i = 0; i < n; i++)
	{
		for(int st = 0; (1 << st) <= m; st++)
		{
			for(int j = 0; j < m + 1 - (1 << st); j++)
			{
				if(st == 0)
				{
					table[i][st][j] = dp[i][j];
					continue;
				}
				table[i][st][j] = min(table[i][st - 1][j], table[i][st - 1][j + (1 << (st - 1))]);
			}
		}
	}
}
inline int get_min(int i, int l, int r)
{
	int st = p[r - l + 1];
	return min(table[i][st][l], table[i][st][r + 1 - (1 << st)]);
}

inline int get_value(int r1, int c1, int r2, int c2)
{
	if(r1 > r2 || c1 > c2)
	{
		return 0;
	}
	return pref[r2 + 1][c2 + 1] + pref[r1][c1] - pref[r2 + 1][c1] - pref[r1][c2 + 1];
}

inline void update_ans(int r1, int c1, int r2, int c2)
{
	int here = get_value(r1 + 1, c1 + 1, r2 - 1, c2 - 1) + 2 * (c2 - c1 + r2 - r1) - 4;
	//cout << here << endl;
	here -= get_value(r1, c1 + 1, r1, c2 - 1);
	here -= get_value(r2, c1 + 1, r2, c2 - 1);
	here -= get_value(r1 + 1, c1, r2 - 1, c1);
	here -= get_value(r1 + 1, c2, r2 - 1, c2);
	//cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
	res = min(res, here);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    p[1] = 0;
    for(int i = 2; i < 1000; i++)
    {
    	p[i] = p[i / 2] + 1;
    }
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n >> m;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	build_pref();
    	build_dp();
    	build_table();
    	res = 16;
    	for(int i = 0; i < n - 4; ++i)
    	{
    		for(int j = 0; j < m - 3; ++j)
    		{
    			for(int k = j + 3; k < m; ++k)
    			{
    				int now = i + 4;
    				while(true)
    				{
    					update_ans(i, j, now, k);
    					now = get_min(now, j + 1, k - 1);
    					if(now == n || get_value(i + 1, j + 1, now - 1, k - 1) >= res)
    					{
    						break;
    					}
    				}
    			}
    		}
    	}
    	cout << res << '\n';
    }
}