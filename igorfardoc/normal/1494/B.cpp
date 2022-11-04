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
    	int n, u, r, d, l;
    	cin >> n >> u >> r >> d >> l;
    	bool ok = true;
    	for(int a1 = 0; (a1 < 2) && ok; a1++)
    	{
    		for(int a2 = 0; (a2 < 2) && ok; a2++)
	    	{
	    		for(int a3 = 0; (a3 < 2) && ok; a3++)
		    	{
		    		for(int a4 = 0; (a4 < 2) && ok; a4++)
			    	{
			    		int u1 = u - a1 - a2;
			    		int r1 = r - a2 - a3;
			    		int d1 = d - a3 - a4;
			    		int l1 = l - a1 - a4;
			    		//cout << u1 << r1 << d1 << l1 << endl;
			    		if(l1 < 0 || r1 < 0 || u1 < 0 || d1 < 0)
			    		{
			    			continue;
			    		}
			    		if(l1 > n - 2 || r1 > n - 2 || u1 > n - 2 || d1 > n - 2)
			    		{
			    			continue;
			    		}
			    		ok = false;
			    		cout << "YES\n";
			    	}
		    	}
	    	}	
    	}
    	if(ok)
    	{
    		cout << "NO\n";
    	}
    }
}