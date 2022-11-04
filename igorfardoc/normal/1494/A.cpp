#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(string a)
{
	int now = 0;
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] == '(')
		{
			++now;
		}
		else
		{
			--now;
		}
		if(now < 0)
		{
			return false;
		}
	}
	return now == 0;
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
    	int n = s.length();
    	if(s[0] == s[n - 1])
    	{
    		cout << "NO\n";
    		continue;
    	}
    	string s1 = "";
    	string s2 = "";
    	for(int i = 0; i < n; i++)
    	{
    		if(s[i] == s[0])
    		{
    			s1 += '(';
    			s2 += '(';
    		}
    		else if(s[i] == s[n - 1])
    		{
    			s1 += ')';
    			s2 += ')';
    		}
    		else
    		{
    			s1 += '(';
    			s2 += ')';
    		}
    	}
    	if(check(s1) || check(s2))
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}