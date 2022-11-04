#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll _gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return _gcd(b, a % b);
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
    	int n, w;
    	cin >> n >> w;
    	multiset<int> s;
    	for(int i = 0; i < n; i++)
    	{
    		int a;
    		cin >> a;
    		s.insert(a);
    	}
    	int ans = 1;
    	int here = w;
    	while(!s.empty())
    	{
    		auto it = s.upper_bound(here);
    		if(it == s.begin())
    		{
    			++ans;
    			here = w;
    			continue;
    		}
    		--it;
    		here -= *it;
    		s.erase(it);
    	}
    	cout << ans << '\n';
    }
}