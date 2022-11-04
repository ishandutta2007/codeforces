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
    int t;
    cin >> t;
    while(t--)
    {
    	int k, n, m;
    	cin >> k >> n >> m;
    	vector<int> a(n), b(m);
    	vector<int> res;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	for(int i = 0; i < m; i++)
    	{
    		cin >> b[i];
    	}
    	int c1 = 0;
    	int c2 = 0;
    	for(int i = 0; i < n + m; i++)
    	{
    		int take = 0;
    		if(c1 < n && c2 < m && b[c2] < a[c1])
    		{
    			take = 1;
    		}
    		if(c1 == n)
    		{
    			take = 1;
    		}
    		if(take == 0)
    		{
    			if(k < a[c1])
    			{
    				break;
    			}
    			if(a[c1] == 0)
    			{
    				++k;
    			}
    			res.push_back(a[c1++]);

    		}
    		else
    		{
    			if(k < b[c2])
    			{
    				break;
    			}
    			if(b[c2] == 0)
    			{
    				++k;
    			}
    			res.push_back(b[c2++]);
    		}
    	}
    	if(res.size() != n + m)
    	{
    		cout << "-1\n";
    		continue;
    	}
    	for(int i = 0; i < n + m; i++)
    	{
    		cout << res[i] << ' ';
    	}
    	cout << '\n';
    }
}