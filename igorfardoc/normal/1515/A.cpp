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
    	int n, x;
    	cin >> n >> x;
    	vector<int> a(n);
    	int sum = 0;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		sum += a[i];
    	}
    	if(sum == x)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	cout << "YES\n";
    	sort(a.begin(), a.end());
    	sum = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		sum += a[i];
    		if(sum == x)
    		{
    			int k = a[i];
    			a[i] = a[i + 1];
    			a[i + 1] = k;
    			break;
    		}
    	}
    	for(int i = 0; i < n; i++)
    	{
    		cout << a[i] << ' ';
    	}
    	cout << '\n';
    }
}