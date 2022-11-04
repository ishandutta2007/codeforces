#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



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
    	long long n, m, r, c;
    	cin >> n >> m >> r >> c;
    	--r;
    	--c;
    	long long ans = -1;
    	ans = max(ans, r + c);
    	ans = max(ans, n - 1 - r + m - 1 - c);	
    	ans = max(ans, r + m - 1 - c);
    	ans = max(ans, c + n - 1 - r);
    	cout << ans << endl;
    }
}