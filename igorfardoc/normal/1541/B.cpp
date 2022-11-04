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
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	int res = 0;
    	for(int i = 0; i < n; i++)
    	{
    		if((ll)a[i] * a[i] >= 2 * n)
    		{
    			continue;
    		}
    		for(int j = 0; j < n; j++)
    		{
    			if(i == j || a[j] < a[i])
    			{
    				continue;
    			}
    			res += (i + j + 2 == (ll)a[i] * a[j]);
    		}	
    	}
    	cout << res << '\n';
    }
}