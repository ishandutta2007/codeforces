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
    	ll now = 0;
    	bool ok = true;
    	for(int i = 0; i < n; i++)
    	{
    		if(now + a[i] < i)
    		{
    			cout << "NO\n";
    			ok = false;
    			break;
    		}
    		now = now + a[i] - i;
    	}
    	if(ok)
    	{
    		cout << "YES\n";
    	}
    }
}