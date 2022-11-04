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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int amount0 = 0;
    int amount1 = 0;
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	if(a[i])
    	{
    		amount1++;
    	}
    	else
    	{
    		amount0++;
    	}
    }
    for(int i = 0; i < q; i++)
    {
    	int c, d;
    	cin >> c >> d;
    	--d;
    	if(c == 1)
    	{
    		a[d] = 1 - a[d];
    		if(a[d])
    		{
    			amount1++;
    			amount0--;
    		}
    		else
    		{
    			amount1--;
    			amount0++;
    		}
    	}
    	else
    	{
    		if(d < amount1)
    		{
    			cout << "1\n";
    		}
    		else
    		{
    			cout << "0\n";
    		}
    	}
    }
}