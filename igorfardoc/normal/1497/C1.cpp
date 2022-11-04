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
    	int n, k;
    	cin >> n >> k;
    	if(n % 2 == 1)
    	{
    		cout << "1 " << n / 2 << ' ' << n / 2 << '\n';
    	}
    	else if(n % 4 == 0)
    	{
    		cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << '\n';
    	}
    	else
    	{
    		cout << "2 " << (n - 2) / 2 << ' ' << (n - 2) / 2 << '\n';
    	}
    }
}