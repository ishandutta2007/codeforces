#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
    	vi a(n);
    	set<int> s1;
    	set<int, greater<int>> s;
    	for(int i = 1; i <= n; i++)
    	{
    		s.insert(i);
    	}
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		auto it = s.find(a[i]);
    		if(it != s.end())
    		{
    			s.erase(it);
    		}
    	}
    	vector<int> b(n, -1);
    	int am = 0;
    	if(s.size() != 1)
    	{
    		vector<int> poses;
	    	for(int i = 0; i < n; i++)
	    	{
	    		if(s1.find(a[i]) == s1.end())
	    		{
	    			++am;
	    			b[i] = a[i];
	    			s1.insert(b[i]);
	    			continue;
	    		}
	    		b[i] = *(s.begin());
	    		if(b[i] == i + 1)
	    		{
	    			poses.push_back(i);
	    		}
	    		s.erase(s.begin());
	    	}
	    	if(poses.size() == 1)
	    	{
	    		for(int i = 0; i < n; i++)
	    		{
	    			if(b[i] != i + 1 && b[i] != a[i])
	    			{
	    				poses.push_back(i);
	    				break;
	    			}
	    		}
	    	}
	    	auto c = b;
	    	for(int i = 0; i < poses.size(); i++)
	    	{
	    		c[poses[i]] = b[poses[(i + 1) % poses.size()]];
	    	}
	    	b = c;
	    }
	    else
	    {
	    	vector<vector<int>> a1(n + 1);
	    	for(int i = 0; i < n; i++)
	    	{
	    		a1[a[i]].push_back(i);
	    	}
	    	int spec = -1;
	    	int value = *(s.begin());
	    	for(int i = 1; i <= n; i++)
	    	{
	    		if(a1[i].size() == 2)
	    		{
	    			if(value == a1[i][0] + 1)
	    			{
	    				spec = a1[i][1];
	    			}
	    			else
	    			{
	    				spec = a1[i][0];
	    			}
	    		}
	    	}
	    	b[spec] = value;
	    	for(int i = 0; i < n; i++)
	    	{
	    		if(b[i] != -1)
	    		{
	    			continue;
	    		}
	    		if(s1.find(a[i]) == s1.end())
	    		{
	    			++am;
	    			b[i] = a[i];
	    			s1.insert(b[i]);
	    			continue;
	    		}
	    	}
		}
    	cout << am << '\n';
    	for(int i = 0; i < n; i++)
    	{
    		cout << b[i] << ' ';
    	}
    	cout << '\n';
    }
}