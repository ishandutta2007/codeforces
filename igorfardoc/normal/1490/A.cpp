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
    	int ans = 0;
    	for(int i = 0; i < n - 1; i++)
    	{
    		int max1 = max(a[i], a[i + 1]);
    		int min1 = min(a[i], a[i + 1]);
    		while((max1 - 1) / min1 + 1 > 2)
    		{
    			min1 *= 2;
    			++ans;
    		}
    	}
    	cout << ans << '\n';
    }
}