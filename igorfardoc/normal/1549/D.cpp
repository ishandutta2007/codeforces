#include<bits/stdc++.h>
#define LOG 19
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
    vector<int> p(300000);
    p[1] = 0;
    for(int i = 2; i < 300000; i++)
    {
    	p[i] = p[i / 2] + 1;
    }
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	vector<ll> a(n), b(n - 1);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		if(i != 0)
    		{
    			b[i - 1] = abs(a[i] - a[i - 1]);
    		}
    	}
    	vector<vector<ll>> table(LOG, vector<ll>(n - 1));
    	for(int st = 0; (1 << st) <= n - 1; ++st)
    	{
    		for(int i = 0; i < (n - (1 << st)); ++i)
    		{
    			if(st == 0)
    			{
    				table[st][i] = b[i];
    				continue;
    			}
    			table[st][i] = _gcd(table[st - 1][i], table[st - 1][i + (1 << (st - 1))]);
    		}
    	}
    	int res = 1;
    	for(int i = 0; i < n - 1; i++)
    	{
    		int l = 0;
    		int r = n - i;
    		while(r - l > 1)
    		{
    			int mid = (l + r) / 2;
    			//cout << mid << ' ' << p[mid] << ' ' << i << ' ' << i + mid - (1 << p[mid]) << endl;
    			ll here = _gcd(table[p[mid]][i], table[p[mid]][i + mid - (1 << p[mid])]);
    			//cout << "END" << endl;
    			if(here > 1)
    			{
    				l = mid;
    			}
    			else
    			{
    				r = mid;
    			}
    		}
    		res = max(res, l + 1);
    	}
    	cout << res << '\n';
    }
}