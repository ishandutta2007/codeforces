#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool sqrt1(int n)
{
	for(int i = 1; i * i <= n; i++)
	{
		if(i * i == n)
		{
			return true;
		}
	}
	return false;
}


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
    	if(n % 2 == 1)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	n /= 2;
    	if(sqrt1(n))
    	{
    		cout << "YES\n";
    		continue;
    	}
    	if(n % 2 == 0 && sqrt1(n / 2))
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}