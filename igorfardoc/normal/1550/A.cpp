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
    	int now = 0;
    	for(int i = 1; i < 5000; i += 2)
    	{
    		now += i;
    		if(now >= n)
    		{
    			cout << (i + 2) / 2 << '\n';
    			break;
    		}
    	}
    }
}