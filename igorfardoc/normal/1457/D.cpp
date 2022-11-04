#include<bits/stdc++.h>
#define int long long
using namespace std;



signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vector<int> mass(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> mass[i];
    }
    if(n > 100)
    {
    	cout << 1;
    	return 0;
    }
    int ans = 1000000000;
    for(int i = 0; i < n - 1; i++)
    {
    	int a = 0;
    	for(int j = i + 1; j < n; j++)
    	{
    		a = a ^ mass[j];
    		int b = 0;
    		for(int k = i; k >= 0; k--)
    		{
    			b = b ^ mass[k];
    			if(a < b)
    			{
    				ans = min(ans, j - 1 - k);
    			}
    		}
    	}
    }
    if(ans == 1000000000)
    {
    	cout << -1;
    }
    else
    {
    	cout << ans;
    }
}