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
    	set<pair<int, int> > s;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		s.insert({a[i], i});
    	}
    	vector<int> ans;
    	int now = n;
    	for(int i = 0; i < n; i++)
    	{
    		auto p = *(--(s.end()));
    		s.erase(--(s.end()));
    		if(p.second < now)
    		{
    			for(int j = p.second; j < now; j++)
    			{
    				ans.push_back(a[j]);
    			}
    			now = p.second;
    		}
    	}
    	for(int i = 0; i < n; i++)
    	{
    		cout << ans[i] << ' ';
    	}
    	cout << '\n';
    }
}