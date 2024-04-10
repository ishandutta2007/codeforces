#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(string s)
{
	int a1 = 0;
	int a2 = 0;
	int n = 10;
	for(int i = 0; i < 10; i++)
	{
		if(s[i] == '1' && i % 2 == 0)
		{
			++a1;
		}
		if(s[i] == '1' && i % 2 == 1)
		{
			++a2;
		}
		int can1 = (n - i - 1) / 2;
		int can2 = (n - i - 2) / 2 + 1;
		if(can1 + a1 < a2 || can2 + a2 < a1)
		{
			return i + 1;
		}
	}
	return 10;
}

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
    	int n = 10;
    	string s1 = s;
    	for(int i = 0; i < 10; i++)
    	{
    		if(s1[i] == '?')
    		{
    			if(i % 2 == 0)
    			{
    				s1[i] = '1';
    			}
    			else
    			{
    				s1[i] = '0';
    			}
    		}
    	}
    	int res = 10;
    	res = min(res, check(s1));
    	s1 = s;
    	for(int i = 0; i < 10; i++)
    	{
    		if(s1[i] == '?')
    		{
    			if(i % 2 == 1)
    			{
    				s1[i] = '1';
    			}
    			else
    			{
    				s1[i] = '0';
    			}
    		}
    	}
    	res = min(res, check(s1));
    	cout << res << '\n';
    }
}