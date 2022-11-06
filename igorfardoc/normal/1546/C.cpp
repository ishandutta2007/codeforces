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
    	vector<pair<int, int>> b(100000, {0, 0});
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		--a[i];
    		if(i % 2 == 0)
    		{
    			b[a[i]].first++;
    		}
    		else
    		{
    			b[a[i]].second++;
    		}
    	}
    	int prev = 0;
    	bool ok = true;
    	for(int i = 0; i < 100000; i++)
    	{
    		if(b[i].first + b[i].second == 0)
    		{
    			continue;
    		}
    		int last = prev - 1 + b[i].first + b[i].second;
    		int amount0 = (last - prev + 1) / 2;
    		int amount1 = amount0;
    		if((last - prev + 1) % 2 == 1)
    		{
    			if(prev % 2 == 0)
    			{
    				++amount0;
    			}
    			else
    			{
    				++amount1;
    			}
    		}
    		if(b[i].first != amount0 || b[i].second != amount1)
    		{
    			ok = false;
    			break;
    		}
    		prev = last + 1;
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