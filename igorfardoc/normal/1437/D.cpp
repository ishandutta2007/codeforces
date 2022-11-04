#include<bits/stdc++.h>
using namespace std;
int n;




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	if(n == 2)
    	{
    		cout << 1 << "\n";
    		continue;
    	}
    	int ans = 1;
    	int can = 1;
    	int now = 0;
    	for(int i = 1; i < n; i++)
    	{
    		if(i != n - 1)
    		{
    			if(a[i + 1] < a[i])
    			{
    				can--;
    			}
    			now++;
    			if(can == 0)
    			{
    				can = now;
    				now = 0;
    				ans++;
    			}
    		}
    	}
    	cout << ans << "\n";
    }
}