#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> get(int a)
{
	vector<int> res;
	int now = 2;
	while(now * now <= a)
	{
		int am = 0;
		while(a % now == 0)
		{
			++am;
			a /= now;
		}
		if(am % 2 == 1)
		{
			res.push_back(now);
		}
		++now;
	}
	if(a != 1)
	{
		res.push_back(a);
	}
	return res;
}


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
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	int ans = 1;
    	set<vector<int> > s;
    	s.insert(get(a[0]));
    	for(int i = 1; i < n; i++)
    	{
    		vector<int> here = get(a[i]);
    		if(s.find(here) != s.end())
    		{
    			++ans;
    			s.clear();
    		}
    		s.insert(here);
    	}
    	cout << ans << '\n';
    }
}