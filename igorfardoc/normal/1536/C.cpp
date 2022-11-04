#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int _gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return _gcd(b, a % b);
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
    	string s;
    	cin >> s;
    	map<pair<int, int>, int> d;
    	int a = 0;
    	int b = 0;
    	for(int i = 0; i < n; i++)
    	{
    		if(s[i] == 'D')
    		{
    			++a;
    		}
    		else
    		{
    			++b;
    		}
    		int g = _gcd(a, b);
    		cout << ++d[{a / g, b / g}] << ' ';
    	}
    	cout << '\n';
    }
}