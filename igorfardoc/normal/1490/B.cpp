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
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	vector<int> c(3, 0);
    	for(int i = 0; i < n; i++)
    	{
    		c[a[i] % 3]++;
    	}
    	int ans = 0;
    	int need = n / 3;

    	for(int i = 0; i < 10; i++)
    	{
    		if(c[i % 3] > need)
    		{
    			ans += c[i % 3] - need;
    			c[(i + 1) % 3] += c[i % 3] - need;
    			c[i % 3] = need;
    		}
    	}
    	cout << ans << '\n';
    }
}