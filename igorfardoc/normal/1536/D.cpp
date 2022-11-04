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
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	set<int> s;
    	s.insert(a[0]);
    	int now = a[0];
    	bool ok = true;
    	for(int i = 1; i < n; i++)
    	{
    		if(now == a[i])
    		{
    			continue;
    		}
    		if(a[i] > now)
    		{
    			if(s.upper_bound(now) == s.end() || *(s.upper_bound(now)) >= a[i])
    			{
    				s.insert(a[i]);
    				now = a[i];
    				continue;
    			}
    			ok = false;
    			break;
    		}
    		else
    		{
    			if(s.lower_bound(now) == s.begin() || *(--s.lower_bound(now)) <= a[i])
    			{
    				s.insert(a[i]);
    				now = a[i];
    				continue;
    			}
    			ok = false;
    			break;
    		}
    	}
    	if(ok)
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}