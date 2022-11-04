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
    	int n, m, k;
    	cin >> n >> m >> k;
    	if(n == 1 && m == 0 && k >= 2)
    	{
    		cout << "YES\n";
    		continue;
    	}
    	if(m < n - 1 || k <= 2 || (ll)n * (n - 1) / 2 < m)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	if(k >= 4)
    	{
    		cout << "YES\n";
    		continue;
    	}
    	if((ll)n * (n - 1) / 2 == m)
    	{
    		cout << "YES\n";
    		continue;
    	}
    	cout << "NO\n";
    }
}