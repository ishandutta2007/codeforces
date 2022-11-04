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
    	int n, m;
    	cin >> n >> m;
    	string s;
    	cin >> s;
    	for(int i = 0; i < min(n, m); i++)
    	{
    		string s1 = s;
    		for(int j = 0; j < n; j++)
    		{
    			if(s[j] == '1')
    			{
    				continue;
    			}
    			if(j == 0 && j == n - 1)
    			{
    				continue;
    			}
    			if(j == 0)
    			{
    				if(s[j + 1] == '1')
    				{
    					s1[j] = '1';
    				}
    				continue;
    			}
    			if(j == n - 1)
    			{
    				if(s[j - 1] == '1')
    				{
    					s1[j] = '1';
    				}
    				continue;
    			}
    			int sum = (int)(s[j - 1] == '1') + (int)(s[j + 1] == '1');
    			if(sum == 1)
    			{
    				s1[j] = '1';
    			}
    		}
    		s = s1;
    	}
    	cout << s << '\n';
    }
}