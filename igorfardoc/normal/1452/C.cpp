#include<bits/stdc++.h>
using namespace std;




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	string s;
    	cin >> s;
    	set<int> set1;
    	int ans = 0;
    	for(int i = 0; i < s.size(); i++)
    	{
    		if(s[i] == ')')
    		{
    			set1.insert(i);
    		}
    	}
    	for(int i = 0; i < s.size(); i++)
    	{
    		if(s[i] == '(')
    		{
    			auto it = set1.upper_bound(i);
    			if(it == set1.end())
    			{
    				break;
    			}
    			++ans;
    			set1.erase(it);
    		}
    	}
    	set1.clear();
    	for(int i = 0; i < s.size(); i++)
    	{
    		if(s[i] == ']')
    		{
    			set1.insert(i);
    		}
    	}
    	for(int i = 0; i < s.size(); i++)
    	{
    		if(s[i] == '[')
    		{
    			auto it = set1.upper_bound(i);
    			if(it == set1.end())
    			{
    				break;
    			}
    			++ans;
    			set1.erase(it);
    		}
    	}
    	cout << ans << endl;
    }
}