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
    	string s;
    	cin >> s;
    	int n = s.length();
    	vector<int> pref10(n + 1, 0), pref11(n + 1, 0), pref01(n + 1, 0), pref00(n + 1, 0);
    	for(int i = 1; i <= n; i++)
    	{
    		pref10[i] = pref10[i - 1];
    		pref11[i] = pref11[i - 1];
    		pref00[i] = pref00[i - 1];
    		pref01[i] = pref01[i - 1];
    		if(i % 2 == 1)
    		{
    			if(s[i - 1] == '0')
    			{
    				pref00[i]++;
    			}
    			else if(s[i - 1] == '1')
    			{
    				pref10[i]++;
    			}
    		}
    		else
    		{
    			if(s[i - 1] == '0')
    			{
    				pref01[i]++;
    			}
    			else if(s[i - 1] == '1')
    			{
    				pref11[i]++;
    			}
    		}
    	}
    	ll ans = 0;
    	for(int i = 0; i < n; i++)
    	{
    		int r = n;
    		int l = i;
    		while(r - l > 1)
    		{
    			int mid = (l + r) / 2;
				if((pref10[mid + 1] - pref10[i] == 0 && pref01[mid + 1] - pref01[i] == 0) ||
					(pref11[mid + 1] - pref11[i] == 0 && pref00[mid + 1] - pref00[i] == 0))
				{
					l = mid;
    			}
    			else
    			{
    				r = mid;
    			}
    		}
    		ans += l - i + 1;
    	}
    	cout << ans << '\n';
    }
}