#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int dp[201][201];
vector<vector<int>> g;
vector<bool> is_near;
vector<int> sz;
int obr1[400];
int res = 0;
int between;
int am_between;
int n;

int bin_pow(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a;
	}
	int res = bin_pow(a, b / 2);
	res = ((ll)res * res) % mod;
	if(b & 1)
	{
		res = ((ll)res * a) % mod;
	}
	return res;
}

int obr(int a)
{
	return bin_pow(a, mod - 2);
}

void dfs(int v, int p, int u)
{
	if(v == u)
	{
		is_near[v] = true;
		sz[v] = 0;
		return;
	}
	sz[v] = 1;
	for(auto u1 : g[v])
	{
		if(u1 == p)
		{
			continue;
		}
		dfs(u1, v, u);
		sz[v] += sz[u1];
		is_near[v] = is_near[v] || is_near[u1];
	}
	if(is_near[v])
	{
		++am_between;
	}
}

int dfs2(int v, int p, int u)
{
	if(v == u)
	{
		return 0;
	}
	int res;
	for(auto u1 : g[v])
	{
		if(u1 == p)
		{
			continue;
		}
		res = dfs2(u1, v, u);
		if(res != -1)
		{
			return res + 1;
		}
	}
	return -1;
}
void dfs3(int v, int p, int u, int depth)
{
	if(v == u)
	{
		return;
	}
	int sz_here = 1;
	int next = -1;
	for(auto u1 : g[v])
	{
		if(u1 == p)
		{
			continue;
		}
		if(is_near[u1])
		{
			next = u1;
			continue;
		}
		sz_here += sz[u1];
	}
	int here = ((ll)sz_here * obr1[n]) % mod;
	here = ((ll)here * dp[am_between - depth][depth]) % mod;
	res = (res + here) % mod;
	dfs3(next, v, u, depth + 1);
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
    for(int i = 1; i < 400; i++)
    {
    	obr1[i] = obr(i);
    }
    for(int i = 0; i <= 200; i++)
    {
    	for(int j = 0; j <= 200; j++)
    	{
    		if(i == 0 && j == 0)
    		{
    			continue;
    		}
    		if(i == 0)
    		{	
    			dp[i][j] = 1;
    			continue;
    		}
    		if(j == 0)
    		{
    			dp[i][j] = 0;
    			continue;
    		}
    		dp[i][j] = ((ll)dp[i - 1][j] * obr1[2] + (ll)dp[i][j - 1] * obr1[2]) % mod;
    	}
    }
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
    	int v, u;
    	cin >> v >> u;
    	--u;
    	--v;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    sz.resize(n);
    for(int v = 0; v < n; ++v)
    {
    	for(int u = v + 1; u < n; ++u)
    	{
    		is_near.assign(n, false);
    		am_between = 0;
    		between = 0;
    		dfs(v, -1, u);
    		int near_v = 0;
    		int near_u = 0;
    		int prev_near = -1;
    		for(auto u1 : g[v])
    		{
    			if(is_near[u1])
    			{
    				prev_near = u1;
    				between = sz[u1];
    			}
    			else
    			{
    				near_v += sz[u1];
    			}
    		}
    		near_u = n - near_v - between - 2;
    		//cout << v << ' ' << u << ' ' << near_v << ' ' << near_u << ' ' << between << ' ' << am_between << endl;
    		res = (res + (ll)(near_u + 1) * obr1[n]) % mod;
    		int rast = dfs2(v, -1, u);
    		//cout << v << ' ' << u << ' ' << prev_near << endl;
    		dfs3(prev_near, v, u, 1);
    	}
    }
    cout << res;
}