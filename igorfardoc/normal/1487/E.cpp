#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    vector<int> n(4);
    for(int i = 0; i < 4; i++)
    {
    	cin >> n[i];
    }
    vector<vector<int> > a(4);
    for(int i = 0; i < 4; i++)
    {
    	a[i].resize(n[i]);
    	for(int j = 0; j < n[i]; j++)
    	{
    		cin >> a[i][j];
    	}
    }
    vector<int> m(3);
    vector<vector<pair<int, int> > > g(3);
    for(int i = 0; i < 3; i++)
    {
    	cin >> m[i];
    	g[i].resize(m[i]);
    	for(int j = 0; j < m[i]; j++)
    	{
    		int x, y;
    		cin >> x >> y;
    		x--;
    		y--;
    		g[i][j] = {x, y};
    	}
    }
    vector<int> dp(n[0]);
    for(int i = 0; i < n[0]; i++)
    {
    	dp[i] = a[0][i];
    }
    for(int i = 1; i < 4; i++)
    {
    	vector<pair<int, int> > p(n[i - 1]);
    	for(int j = 0; j < n[i - 1]; j++)
    	{
    		p[j] = {dp[j], j};
    	}
    	p.push_back({INF, -1});
    	sort(p.begin(), p.end());
    	vector<int> dp1(n[i], INF);
    	for(int j = 0; j < n[i]; j++)
    	{
    		dp1[j] = min((ll)dp1[j], (ll)a[i][j] + p[0].first);
    	}
    	vector<int> pointers(n[i], 0);
    	vector<pair<pair<int, int>, int> > r(m[i - 1]);
    	for(int j = 0; j < m[i - 1]; j++)
    	{
    		auto pair1 = g[i - 1][j];
    		r[j] = {{dp[pair1.first], pair1.first}, pair1.second};
    	}
    	sort(r.begin(), r.end());
    	for(int j = 0; j < m[i - 1]; j++)
    	{
    		auto now = r[j];
    		int id2 = now.second;
    		int id1 = now.first.second;
    		if(p[pointers[id2]].second == id1)
    		{
    			pointers[id2]++;
    			dp1[id2] = min((ll)INF, (ll)p[pointers[id2]].first + a[i][id2]);
    		}
    	}
    	dp = dp1;
    }
    int ans1 = INF;
    for(int i = 0; i < n[3]; i++)
    {
    	ans1 = min(ans1, dp[i]);
    }
    if(ans1 == INF)
    {
    	cout << -1;
    }
    else
    {
    	cout << ans1;
    }
}