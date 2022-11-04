#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
vector<string> a;
vector<vector<bool>> b;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n >> m >> k;
    	a.resize(n);
    	b.assign(n, vector<bool>(m, false));
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	for(int i = n - 1; i >= 0; --i)
    	{
    		for(int j = 0; j < m; j++)
    		{
    			if(a[i][j] == '.')
    			{
    				continue;
    			}
    			int max1;
    			for(max1 = 1;; max1++)
    			{
    				if(i - max1 < 0)
    				{
    					break;
    				}
    				if(j + max1 >= m)
    				{
    					break;
    				}
    				if(j - max1 < 0)
    				{
    					break;
    				}
    				if(a[i - max1][j + max1] == '*' && a[i - max1][j - max1] == '*')
    				{
    					continue;
    				}
    				break;
    			}
    			--max1;
    			if(max1 < k)
    			{
    				continue;
    			}
    			for(int l = 0; l <= max1; ++l)
    			{
    				b[i - l][j + l] = true;
    				b[i - l][j - l] = true;
    			}
    		}
    	}
    	bool ok = true;
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < m; j++)
    		{
    			if(a[i][j] == '*' && !b[i][j])
    			{
    				ok = false;
    				break;
    			}
    		}
    		if(!ok)
    		{
    			break;
    		}
    	}
    	if(ok)
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}