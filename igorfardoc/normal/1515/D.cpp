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
    	int n, l, r;
    	cin >> n >> l >> r;
    	vector<int> a(n), b(n);
    	for(int i = 0; i < l; i++)
    	{
    		int c;
    		cin >> c;
    		--c;
    		a[c]++;
    	}
    	for(int i = 0; i < r; i++)
    	{
    		int c;
    		cin >> c;
    		--c;
    		b[c]++;
    	}
    	if(l < r)
    	{
    		swap(l, r);
    		swap(a, b);
    	}
    	int need = (l - r) / 2;
    	int res = n / 2;
    	for(int i = 0; i < n; i++)
    	{
    		if(a[i] > b[i])
    		{
    			int take = min(need, (a[i] - b[i]) / 2);
    			a[i] -= take;
    			b[i] += take;
    			need -= take;
    			res += take;
    		}
    	}
    	for(int i = 0; i < n; i++)
    	{
    		if(a[i] > b[i])
    		{
    			int take = min(need, 1);
    			a[i] -= take;
    			b[i] += take;
    			need -= take;
    			res += take;
    		}
    	}
    	for(int i = 0; i < n; i++)
    	{
			int take = min(need, a[i]);
			a[i] -= take;
			b[i] += take;
			need -= take;
			res += take;
    	}
    	
    	for(int i = 0; i < n; i++)
    	{
    		res -= min(a[i], b[i]);
    	}
    	cout << res << '\n';
    }
}