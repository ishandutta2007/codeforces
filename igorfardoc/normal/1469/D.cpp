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
    	vector<pair<int, int> > res;
    	int now = n;
    	for(int i = n - 1; i >= 1; i--)
    	{
    		if(i >= 3 && ((long long)i * (i - 1) >= now && (long long)(i - 1) * (i - 2) < now))
    		{
    			res.push_back({now, i - 1});
    			res.push_back({now, i});
    			now = i;
    			continue;
    		}
    		else if(i == 2)
    		{
    			int now1 = now;
    			while(now1 >= 2)
    			{
    				res.push_back({now, 2});
    				now1 = (now1 - 1) / 2 + 1;
    			}
    			break;
    		}
    		else
    		{
    			res.push_back({i, now});
    		}
    	}
    	cout << res.size() << '\n';
    	for(int i = 0; i < res.size(); i++)
    	{
    		cout << res[i].first << ' ' << res[i].second << '\n';
    	}
    }
}