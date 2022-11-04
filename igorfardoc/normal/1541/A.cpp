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
    	int n;
    	cin >> n;
    	int to = n / 2;
    	if(n % 2 == 1)
    	{
    		to = (n - 3) / 2;
    	}
    	for(int i = 0; i < to; i++)
    	{
    		cout << (i * 2 + 2) << ' ' << (i * 2 + 1) << ' ';
    	}
    	if(n % 2 == 1)
    	{
    		cout << n << ' ' << n - 2 << ' ' << n - 1;
    	}
    	cout << '\n';
    }
}