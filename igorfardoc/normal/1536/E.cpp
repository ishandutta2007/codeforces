#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int mod = 1000000007;
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
    	int am = 0;
    	int ans = 1;
    	for(int i = 0; i < n * m; i++)
    	{
    		char c;
    		cin >> c;
    		if(c == '#')
    		{
    			++am;
    			ans = ans * 2 % mod;
    		}
    	}
    	if(am == n * m)
    	{
    		ans = (ans - 1 + mod) % mod;
    	}
    	cout << ans << '\n';
    }
}