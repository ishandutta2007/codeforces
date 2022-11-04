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
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	cout << "0 ";
    	int now = a[0];
    	for(int i = 1; i < n; i++)
    	{
    		int here = 0;
    		for(int j = 29; j >= 0; j--)
    		{
    			if(!((now >> j) & 1))
    			{
    				continue;
    			}
    			if(!((a[i] >> j) & 1))
    			{
    				here ^= (1 << j);
    			}
    		}
    		now = here ^ a[i];
    		cout << here << ' ';
    	}
    	cout << '\n';
    }
}