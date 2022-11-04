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
    	int n, m;
    	cin >> n >> m;
    	vector<int> k(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> k[i];
    		k[i]--;
    	}
    	vector<int> c(m);
    	for(int i = 0; i < m; i++)
    	{
    		cin >> c[i];
    	}
    	ll ans = 0;
    	sort(k.begin(), k.end());
    	int now = 0;
    	for(int i = n - 1; i >= 0; i--)
		{
			if(now > k[i])
			{
				ans += c[k[i]];
			}
			else
			{
				ans += c[now++];
			}
		}
		cout << ans << '\n';
    }
}