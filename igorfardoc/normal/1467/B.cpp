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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	vector<bool> ok(n, false);
    	vector<int> tp(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	int ans = 0;
    	int can = 1;
    	for(int i = 1; i < n - 1; i++)
    	{
    		if(a[i] > a[i - 1] && a[i] > a[i + 1])
    		{
    			++ans;
    			ok[i] = true;
    			tp[i] = 1;
    		}
    		if(a[i] < a[i - 1] && a[i] < a[i + 1])
    		{
    			++ans;
    			ok[i] = true;
    			tp[i] = 2;
    		}
    	}
    	for(int i = 0; i < n - 2; i++)
    	{
    		if(ok[i] && ok[i + 1] && ok[i + 2])
    		{
    			can = max(can, 3);
    		}
    	}
		for(int i = 0; i < n - 1; i++)
    	{
    		if(ok[i] && ok[i + 1])
    		{
    			if(i - 2 < 0 || i + 3 >= n)
				{
					can = max(can, 2);
					continue;
				}
    			if(tp[i] == 2)
    			{
    				if(a[i - 2] <= a[i - 1] || a[i + 3] >= a[i + 2])
    				{
    					can = max(can, 2);
						continue;
    				}
    				if(a[i - 1] >= a[i + 1] || a[i] >= a[i + 2])
    				{
    					can = max(can, 2);
						continue;
    				}
    			}
    			if(tp[i] == 1)
    			{
    				if(a[i - 2] >= a[i - 1] || a[i + 3] <= a[i + 2])
    				{
    					can = max(can, 2);
						continue;
    				}
    				if(a[i - 1] <= a[i + 1] || a[i] <= a[i + 2])
    				{
    					can = max(can, 2);
						continue;
    				}
    			}
    		}
    	}
    	cout << max(0, ans - can) << '\n';
    }
}