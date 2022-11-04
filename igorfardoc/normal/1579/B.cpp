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
    	auto b = a;
    	sort(b.begin(), b.end());
    	vector<pair<pair<int, int>, int>> ans;
    	for(int i = 0; i < n - 1; i++)
    	{
    		if(a[i] == b[i])
    		{
    			continue;
    		}
    		for(int j = i + 1; j < n; j++)
    		{
    			if(b[i] == a[j])
    			{
    				int d = j - i;
    				ans.push_back({{i + 1, j + 1}, j - i});
    				auto anew = a;
    				for(int k = i; k <= j; k++)
    				{
    					int here = k + d;
    					if(here > j)
    					{
    						here -= d + 1;
    					}
    					anew[k] = a[here];
    				}
    				a = anew;
    				break;
    			}

    		}
    	}
    	cout << ans.size() << '\n';
    	for(int i = 0; i < ans.size(); i++)
    	{
    		cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second << '\n';
    	}
    }
}