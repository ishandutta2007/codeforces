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
    	int min1 = 100000;
    	int amount = 0;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		if(a[i] < min1)
    		{
    			min1 = a[i];
    			amount = 0;
    		}
    		if(a[i] == min1)
    		{
    			++amount;
    		}
    	}
    	cout << n - amount << '\n';
    }
}