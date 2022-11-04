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
    	string s, t;
    	cin >> s >> t;
    	int n = s.size();
    	if(t.size() > s.size())
    	{
    		cout << "NO\n";
    		continue;
    	}
    	int now = 0;
    	int ch = 0;
    	int last = 0;
    	for(int i = 0; i < s.size(); i++)
    	{
    		if(now == t.size())
    		{
    			break;
    		}
    		if(s[i] == t[now] && i % 2 == ch)
    		{
    			last = i;
    			ch = 1 - ch;
    			++now;
    		}
    	}
    	if(now == t.size() && (n - last) % 2 == 1)
    	{
    		cout << "YES\n";
    		continue;
    	}
    	now = 0;
    	ch = 1;
    	last = 0;
    	for(int i = 0; i < s.size(); i++)
    	{
    		if(now == t.size())
    		{
    			break;
    		}
    		if(s[i] == t[now] && i % 2 == ch)
    		{
    			ch = 1 - ch;
    			last = i;
    			++now;
    		}
    	}
    	if(now == t.size() && (n - last) % 2 == 1)
    	{
    		cout << "YES\n";
    		continue;
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}