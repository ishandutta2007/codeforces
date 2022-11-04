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
    	ll s = 0;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		s += a[i];
    	}
    	ll a1 = 0;
    	for(int i = 0; i < n; i++)
    	{
    		if(i % 2 == 0)
    		{
    			a1 += a[i] - 1;
    		}
    	}
    	if(2 * a1 <= s)
    	{
    		for(int i = 0; i < n; i++)
    		{
    			if(i % 2 == 0)
    			{
    				cout << 1 << ' ';
    			}
    			else
    			{
    				cout << a[i] << ' ';
    			}
    		}
    	}
    	else
    	{
    		for(int i = 0; i < n; i++)
    		{
    			if(i % 2 == 1)
    			{
    				cout << 1 << ' ';
    			}
    			else
    			{
    				cout << a[i] << ' ';
    			}
    		}
    	}
    	cout << '\n';
    }
}