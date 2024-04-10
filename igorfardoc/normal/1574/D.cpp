#include<bits/stdc++.h>
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
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> c(n);
    vector<int> res(n);
    ll res1 = 0;
    for(int i = 0; i < n; i++)
    {
    	cin >> c[i];
    	res[i] = c[i] - 1;
    	a[i].resize(c[i]);
    	for(int j = 0; j < c[i]; j++)
    	{
    		cin >> a[i][j];
    	}
    	res1 += a[i][c[i] - 1];
    }
    set<vector<int>> b;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
    	vector<int> res(n);
    	for(int j = 0; j < n; j++)
    	{
    		cin >> res[j];
    		--res[j];
    	}
    	b.insert(res);
    }
    if(b.find(res) != b.end())
    {
    	res1 = -1;
    }
    for(const auto& el : b)
    {
    	vector<int> here = el;
    	ll sumhere = 0;
    	for(int i = 0; i < n; i++)
    	{
    		sumhere += a[i][here[i]];
    	}
    	for(int i = 0; i < n; i++)
    	{
    		if(here[i] != 0)
    		{
    			--here[i];
    			if(b.find(here) == b.end() && sumhere - a[i][here[i] + 1] + a[i][here[i]] > res1)
    			{
    				res1 = sumhere - a[i][here[i] + 1] + a[i][here[i]];
    				res = here;
    			}
    			++here[i];
    		}
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	cout << res[i] + 1 << ' ';
    }
}