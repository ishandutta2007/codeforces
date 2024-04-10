#include<bits/stdc++.h>
using namespace std;




int main()
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
    	int x, y;
    	cin >> x >> y;
    	int ans = 2 * min(x, y);
    	int val = max(x, y) - min(x, y);
    	ans += max(2 * val - 1, 0);
    	cout << ans << endl;
    }
}