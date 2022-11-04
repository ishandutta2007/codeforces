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
    	long double ans = 0;
    	vector<int> x, y;
    	for(int i = 0; i < 2 * n; i++)
    	{
    		int a, b;
    		cin >> a >> b;
    		if(a == 0)
    		{
    			y.push_back(abs(b));
    		}
    		else
    		{
    			x.push_back(abs(a));
    		}
    	}
    	sort(x.begin(), x.end());
    	sort(y.begin(), y.end());
    	for(int i = 0; i < n; i++)
    	{
    		ans += sqrt((long double)x[i] * x[i] + (long double)y[i] * y[i]);
    	}
    	cout << setprecision(15) << fixed << ans << '\n'; 
    }
}