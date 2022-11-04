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
    	int n, d;
    	cin >> n >> d;
    	vector<int> a(n);
    	bool ok1 = true;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		if(a[i] > d)
    		{
    			ok1 = false;
    		}
    	}
    	if(ok1)
    	{
    		cout << "YES\n";
    		continue;
    	}
    	bool ok = true;
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = i + 1; j < n; j++)
    		{
    			if(a[i] + a[j] <= d)
    			{
    				cout << "YES\n";
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
    		cout << "NO\n";
    	}
    }
}