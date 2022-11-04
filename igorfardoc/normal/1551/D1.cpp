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
    	if(m % 2 == 1 && k > m / 2 * n)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	if(n % 2 == 0 && k % 2 == 0)
    	{
    		cout << "YES\n";
    		continue;
    	}
    	if(n % 2 == 0 && k % 2 == 1)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	if(m / 2 > k)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	k -= m / 2;
    	if(k % 2 == 0)
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}