#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	vector<int> d(n + 1, 1);
    	set<int> there;
    	if(n == 1)
    	{
    		cout << 0 << endl;
    		continue;
    	}
    	for(int i = 0; i < n; i++)
    	{
    		there.insert(a[i]);
    		if(i > 0 && i < n - 1)
    		{
    			if(a[i + 1] != a[i])
    			{
    				++d[a[i]];
    			}
    		}
    		else if(n == 1)
    		{
    			break;
    		}
    		else if(i == 0)
    		{
    			d[a[i]]--;
    			if(a[i + 1] != a[i])
    			{
    				++d[a[i]];
    			}
    		}
    	}
    	int min1 = 1000000000;
    	for(int i = 0; i <= n; i++)
    	{
    		if(there.find(i) != there.end())
    		{
    			min1 = min(min1, d[i]);
    		}
    	}
    	cout << min1 << endl;
    }
}