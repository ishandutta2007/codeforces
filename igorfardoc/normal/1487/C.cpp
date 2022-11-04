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
    	if(n % 2 == 1)
    	{
    		int am = n / 2;
    		int now = 0;
    		for(int i = 0; i < n - 1; i++)
    		{
    			if(i > n / 2)
    			{
    				++now;
    			}
    			for(int j = 0; j < am - now; j++)
    			{
    				cout << "1 ";
    			}
    			for(int j = 0; j < (n - i - 1 - (am - now)); j++)
    			{
    				cout << "-1 ";
    			}
    		}
    	}
    	else
    	{
    		int am = (n - 1) / 2;
    		vector<int> need(n, am);
    		for(int i = 0; i < n - 1; i++)
    		{
    			int start = i + 1;
    			if(i % 2 == 0)
    			{
    				start = i + 2;
    				cout << "0 ";
    			}
    			if(i % 2 == 0)
    			{
    				for(int j = start; j < start + (need[i]); j++)
	    			{
	    				cout << "1 ";
	    			}
	    			for(int j = start + (need[i]); j < n; j++)
					{
						cout << "-1 ";
						need[j]--;
					}
    			}
    			else
    			{
    				int there = n - 1 - i;
    				for(int j = start; j < start + (there - need[i]); j++)
	    			{
	    				cout << "-1 ";
	    				need[j]--;
	    			}
	    			for(int j = start + (there - need[i]); j < n; j++)
					{
						cout << "1 ";
					}
    			}
    		}
    	}
    }
}