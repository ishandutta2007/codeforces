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
    	vector<int> a(n + 2);
    	a[0] = 0;
    	for(int i = 1; i <= n; i++)
    	{
    		cin >> a[i];
    	}
    	a[n + 1] = 0;
    	ll ans = 0;
    	for(int i = 1; i <= n; i++)
    	{
    		if(a[i] > a[i + 1] && a[i] > a[i - 1])
    		{
    			ans += a[i] - max(a[i + 1], a[i - 1]);
    			a[i] = max(a[i + 1], a[i - 1]);
    		}
    	}
    	for(int i = 0; i <= n; i++)
    	{
    		ans += abs(a[i + 1] - a[i]);
    	}
    	cout << ans << '\n';
    }
}