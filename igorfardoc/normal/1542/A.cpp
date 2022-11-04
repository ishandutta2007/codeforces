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
    	int a1 = 0;
    	int n;
    	cin >> n;
    	for(int i = 0; i < 2 * n; i++)
    	{
    		int a;
    		cin >> a;
    		if(a % 2 == 0)
    		{
    			++a1;
    		}
    	}
    	if(a1 == n)
    	{
    		cout << "Yes\n";
    	}
    	else
    	{
    		cout << "No\n";
    	}
    }
}