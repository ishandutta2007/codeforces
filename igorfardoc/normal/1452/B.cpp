#include<bits/stdc++.h>
using namespace std;




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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	long long sum = 0;
    	int max1 = 0;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		sum += a[i];
    		max1 = max(a[i], max1);
    	}
    	if(sum == 0)
    	{
    		cout << 0 << endl;
    		continue;
    	}
    	long long need = ((sum - 1) / (n - 1) + 1) * (n - 1);
    	cout << need - sum + (n - 1) * max(0ll, max1 - need / (n - 1)) << endl;
    }
}