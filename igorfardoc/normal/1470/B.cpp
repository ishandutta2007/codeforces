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
    	map<vector<int>, int> d;
    	for(int i = 0; i < n; i++)
    	{
    		vector<int> res;
    		int div = 2;
    		int now = a[i];
    		while(now > 1)
    		{
    			if(div * div > now)
    			{
    				res.push_back(now);
    				break;
    			}
    			int it = 0;
    			while(now % div == 0)
    			{
    				++it;
    				now /= div;
    			}
    			if(it % 2 == 1)
    			{
    				res.push_back(div);
    			}
    			++div;
    		}
    		d[res]++;
    	}
    	//vector<int> res(n + 2, 0);
    	int res1 = 0;
    	int res2 = 0;
    	for(auto it = d.begin(); it != d.end(); ++it)
    	{
    		res1 = max(res1, it->second);
    		if(it->second % 2 == 0 || it->first == vector<int>())
    		{
    			res2 += it->second;
    		}
    	}
    	res2 = max(res1, res2);
    	int q;
    	cin >> q;
    	for(int i = 0; i < q; i++)
    	{
    		ll w;
    		cin >> w;
    		if(w == 0)
    		{
    			cout << res1 << '\n';
    		}
    		else
    		{
    			cout << res2 << '\n';
    		}
    	}
    }
}