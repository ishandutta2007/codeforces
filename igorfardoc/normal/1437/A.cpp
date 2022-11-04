#include<bits/stdc++.h>
using namespace std;
#define int long long



signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	int l, r;
    	cin >> l >> r;
    	int a = 2 * l;
    	if(r - l + 1 > a / 2)
    	{
    		cout << "NO\n";
    	}
    	else
    	{
    		cout << "YES\n";
    	}
    }
}