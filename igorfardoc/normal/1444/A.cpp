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
    	ll p, q;
    	cin >> p >> q;
    	if(q > p)
    	{
    		cout << p << '\n';
    		continue;
    	}
    	if(p % q != 0)
    	{
    		cout << p << '\n';
    		continue;
    	}
    	unordered_map<int, int> div;
    	ll now = q;
    	ll i = 2;
    	while(i * i <= now)
    	{
    		while(now % i == 0)
    		{
    			++div[i];
    			now /= i;
    		}
    		++i;
    	}
    	if(now != 1)
    	{
    		++div[now];
    	}
    	ll res = 1;
    	for(const auto& el : div)
    	{
    		ll now = p;
    		ll am = 1;
    		while(now % el.first == 0)
    		{
    			now /= el.first;
    			am *= el.first;
    		}
    		ll here = 1;
    		for(int i = 0; i < el.second; i++)
    		{
    			here *= el.first;
    		}
    		res = max(res, p / (am / here) / el.first);
    	}
    	cout << res << '\n';
    }
}