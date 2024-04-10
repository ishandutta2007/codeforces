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
    	int a, b, c, m;
    	cin >> a >> b >> c >> m;
    	int n = a + b + c;
    	int max1 = max(a, max(b, c));
    	int can = (n - 1) / 2 + 1;
    	int min1 = max(0, max1 - can) * 2;
    	if(n % 2 == 0)
    	{
    		min1 = max(0, min1 - 1);
    	}
    	int max2 = max(a - 1, 0) + max(b - 1, 0) + max(c - 1, 0);
    	if(m >= min1 && m <= max2)
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}