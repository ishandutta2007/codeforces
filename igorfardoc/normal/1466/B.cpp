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
    	vector<int> am(2 * n + 1, 0);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		am[a[i]]++;
    	}
    	int ans = 0;
    	vector<bool> b(2 * n + 2, false);
    	for(int i = 0; i <= 2 * n; i++)
    	{
    		if(b[i])
    		{
    			if(am[i] != 0)
    			{
    				b[i + 1] = true;
    				++ans;
    			}
    		}
    		else
    		{
    			if(am[i] > 0)
    			{
    				b[i] = true;
    				++ans;
    			}
    			if(am[i] > 1)
    			{
    				b[i + 1] = true;
    				++ans;
    			}
    		}
    	}
    	cout << ans << '\n';
    }
}