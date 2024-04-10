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
    	string s, t;
    	cin >> s >> t;
    	int res = 0;
    	for(int i = 0; i < n; i++)
    	{
    		if(t[i] == '1' && s[i] == '0')
    		{
    			++res;
    			t[i] = '0';
    		}
    	}
    	for(int i = 0; i < n; i++)
    	{
    		if(i != 0 && t[i] == '1' && s[i - 1] == '1')
    		{
    			s[i - 1] = '0';
    			++res;
    		}
    		else if(i != n - 1 && t[i] == '1' && s[i + 1] == '1')
    		{
    			s[i + 1] = '0';
    			++res;
    		}
    	}
    	cout << res << '\n';
    }
}