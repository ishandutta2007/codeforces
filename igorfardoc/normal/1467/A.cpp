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
    	for(int i = 0; i < n; i++)
    	{
    		if(i == 0)
    		{
    			cout << 9;
    		}
    		else if(i == 1)
    		{
    			cout << 8;
    		}
    		else
    		{
    			cout << (i + 7) % 10;
    		}
    	}
    	cout << '\n';
    }
}