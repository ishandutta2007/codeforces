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
    	vector<int> a(n);
        unordered_map<int, int> b;
        vector<int> all;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		b[a[i] % m]++;
            all.push_back(a[i] % m);
    	}
    	int ans = 0;
    	for(int j = 0; j < all.size(); j++)
    	{
            int i = all[j];
    		if(b[i] == 0 && b[(m - i) % m] == 0)
    		{
    			continue;
    		}
    		ans += 1;
    		if(i != 0)
    		{
	    		if(abs(b[i] - b[(m - i) % m]) > 1)
	    		{
	    			ans += abs(b[i] - b[(m - i) % m]) - 1;
	    		}
    		}
    		b[i] = 0;
    		b[(m - i) % m] = 0;
    	}
    	cout << ans << '\n';
    }
}