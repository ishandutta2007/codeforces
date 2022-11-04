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
    	vector<string> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	int ans = 0;
    	for(int i = 0; i < 5; i++)
    	{
    		vector<int> b;
    		for(int j = 0; j < n; j++)
    		{
    			int am1 = 0;
    			int am2 = 0;
    			for(int k = 0; k < a[j].size(); k++)
    			{
    				if(a[j][k] == (char)('a' + i))
    				{
    					++am1;
    				}
    				else
    				{
    					++am2;
    				}
    			}
    			b.push_back(am1 - am2);
    		}
    		sort(b.begin(), b.end());
    		int now = 0;
    		for(int j = n - 1; j >= 0; j--)
    		{
    			now += b[j];
    			if(now <= 0)
    			{
    				ans = max(ans, n - j - 1);
    				break;
    			}
    			ans = max(ans, n - j);
    		}
    	}
    	cout << ans << '\n';
    }
}