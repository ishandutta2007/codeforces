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
    	string s, t;
    	cin >> s >> t;
    	int n = s.size();
    	bool ok1 = false;
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = i; j < n && (j - i) < t.size(); j++)
    		{
    			//cout << i << ' ' << j << endl;
    			int now = 0;
    			bool ok = true;
    			for(int k = i; k <= j; ++k)
    			{
    				if(s[k] != t[now++])
    				{
    					ok = false;
    					break;
    				}
    			}
    			if(!ok)
    			{
    				break;
    			}
    			if((int)t.size() - now > j)
    			{
    				continue;
    			}
    			for(int k = j - 1; now < t.size(); --k)
    			{
    				if(s[k] != t[now++])
    				{
    					ok = false;
    					break;
    				}
    			}
    			if(!ok)
    			{
    				continue;
    			}
    			ok1 = true;
    			break;
    		}
    		if(ok1)
    		{
    			break;
    		}
    	}
    	if(ok1)
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}