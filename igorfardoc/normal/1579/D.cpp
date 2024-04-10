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
    	set<pair<int, int>> s;
    	int n;
    	cin >> n;
    	for(int i = 0; i < n; i++)
    	{
    		pair<int, int> a = {-1, i + 1};
    		cin >> a.first;
    		if(a.first == 0)
    		{
    			continue;
    		}
    		s.insert(a);
    	}
    	vector<pair<int, int>> ans;
    	while(s.size() > 1)
    	{
    		auto it = s.end();
    		--it;
    		auto p = *it;
    		s.erase(it);
    		it = s.end();
    		--it;
    		auto p1 = *it;
    		s.erase(it);
    		ans.push_back({p.second, p1.second});
    		--p.first;
    		--p1.first;
    		if(p.first != 0)
    		{
    			s.insert(p);
    		}
    		if(p1.first != 0)
    		{
    			s.insert(p1);
    		}
    	}
    	cout << ans.size() << '\n';
    	for(int i = 0; i < ans.size(); i++)
    	{
    		cout << ans[i].first << ' ' << ans[i].second << '\n';
    	}
    }
}