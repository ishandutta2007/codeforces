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
    	vector<int> a(n - 1);
    	int c;
    	cin >> c;
    	for(int i = 0; i < n - 1; i++)
    	{
    		cin >> a[i];
    	}
    	sort(a.begin(), a.end());
    	ll res = 0;
    	ll sum = 0;
    	for(int i = n - 2; i >= 0; i--)
    	{
    		if(i == n - 2)
    		{
    			sum += a[i];
    			continue;
    		}
    		res -= a[i];
    		res -= sum - (ll)a[i] * (n - 2 - i);
    		sum += a[i];
    	}
    	cout << res << '\n';
    }
}