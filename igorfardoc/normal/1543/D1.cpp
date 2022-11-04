#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ans(int x)
{
	cout << x << endl;
	int val;
	cin >> val;
	return val;
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
    	int n, k;
    	cin >> n >> k;
    	int now = 0;
    	for(int i = 0; i < n; i++)
    	{
    		int here = i ^ now;
    		if(ans(here))
    		{
    			break;
    		}
    		now ^= here;
    	}
    }
}