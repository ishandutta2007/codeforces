#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	int n, k;
    	cin >> n >> k;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	int ansmin = 1000000000;
    	for(int c = 1; c <= 100; c++)
    	{
    		int ans = 0;
    		int i = 0;
    		while(i < n)
    		{
    			if(a[i] == c)
    			{
    				++i;
    				continue;
    			}
    			++ans;
    			i += k;
    		}
    		ansmin = min(ansmin, ans);
    	}
    	cout << ansmin << endl;
    }
}