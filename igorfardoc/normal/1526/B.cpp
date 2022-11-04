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
    	if(n > 100000)
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		bool ok = false;
    		for(int i = 0; i <= n / 111; i++)
    		{	
    			if((n - i * 111) % 11 == 0)
    			{
    				cout << "YES\n";
    				ok = true;
    				break;
    			}
    		}
    		if(!ok)
    		{
    			cout << "NO\n";
    		}
    	}
    }
}