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
    	int n, a, b;
    	cin >> n >> a >> b;
    	ll now = 1;
    	bool ok = true;
    	for(int k = 0; k < 40; k++)
    	{
    		if(now > n)
    		{
    			break;
    		}
    		if((n - now) % b == 0)
    		{
    			cout << "Yes\n";
    			ok = false;
    			break;
    		}
    		now *= a;
    	}
    	if(ok)
    	{
    		cout << "No\n";
    	}
    }
}