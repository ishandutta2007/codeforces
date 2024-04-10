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
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	auto b = a;
    	sort(b.begin(), b.end());
    	bool ok = true;
    	for(int i = n - x; i <= x - 1; i++)
    	{
    		if(a[i] != b[i])
    		{
    			ok = false;
    			break;
    		}
    	}
    	if(ok)
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}