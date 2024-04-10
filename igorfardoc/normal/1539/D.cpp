#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i].second >> a[i].first;
    	sum += a[i].second;
    }
    sort(a.begin(), a.end());
    ll l = 0;
    ll r = 3000000000000000000ll;
    while(r - l > 1)
    {
    	ll mid = (l + r) / 2;
    	if(mid < sum)
    	{
    		l = mid;
    		continue;
    	}
    	if(mid >= sum * 2)
    	{
    		r = mid;
    		continue;
    	}
    	ll here = mid - sum;
    	auto b = a;
    	for(int i = n - 1; i >= 0; i--)
    	{
    		ll minus = min(b[i].second, here);
    		b[i].second -= minus;
    		here -= minus;
    	}
    	bool ok = true;
    	ll now = mid - sum;
    	for(int i = 0; i < n; i++)
    	{
    		if(b[i].second == 0)
    		{
    			continue;
    		}
    		if(now < b[i].first)
    		{
    			ok = false;
    			break;
    		}
    		now += b[i].second;
    	}
    	if(ok)
    	{
    		r = mid;
    	}
    	else
    	{
    		l = mid;
    	}
    }
    cout << r << '\n';
}