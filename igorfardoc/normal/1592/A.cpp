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
    	int n, h;
    	cin >> n >> h;
    	int max1 = -1;
    	int max2 = -1;
    	for(int i = 0; i < n; i++)
    	{
    		int a;
    		cin >> a;
    		if(a > max1)
    		{
    			max2 = max1;
    			max1 = a;
    		}
    		else if(a > max2)
    		{
    			max2 = a;
    		}
    	}
    	int res = h / (max1 + max2);
    	h -= res * (max1 + max2);
    	int ans = 0;
    	if(h > 0)
    	{
    		ans++;
    		h -= max1;
    	}
    	if(h > 0)
    	{
    		ans++;
    	}
    	cout << res * 2 + ans << '\n';
    }
}