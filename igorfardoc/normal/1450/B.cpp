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
    	int n, k;
    	cin >> n >> k;
    	vector<pair<int, int> > a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i].first >> a[i].second;
    	}
    	int it = 0;
    	while(a.size() != 1)
    	{
    		int max1 = -1;
	    	int maxid = -1;
	    	for(int i = 0; i < a.size(); i++)
	    	{
	    		int now = 0;
	    		for(int j = 0; j < a.size(); j++)
		    	{
		    		if(i == j)
		    		{
		    			continue;
		    		}
		    		if(abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) <= k)
		    		{
		    			++now;
		    		}
		    	}
		    	if(now > max1)
		    	{
		    		max1 = now;
		    		maxid = i;
		    	}
	    	}
	    	if(max1 == 0)
	    	{
	    		break;
	    	}
	    	vector<pair<int, int> > anew;
	    	for(int i = 0; i < a.size(); i++)
	    	{
	    		if(i == maxid || abs(a[i].first - a[maxid].first) + abs(a[i].second - a[maxid].second) > k)
	    		{
	    			anew.push_back(a[i]);
	    		}
	    	}
	    	a = anew;
	    	++it;
    	}
    	if(a.size() == 1)
    	{
    		cout << it << endl;
    	}
    	else
    	{
    		cout << -1 << endl;
    	}
    }
}