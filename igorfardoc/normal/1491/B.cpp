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
    	int n, u, v;
	    cin >> n >> u >> v;
	    vector<int> a(n);
	    bool near = false;
	    bool all1 = true;
	    for(int i = 0; i < n; i++)
	    {
	    	cin >> a[i];
	    	if(i != 0 && abs(a[i] - a[i - 1]) > 1)
	    	{
	    		near = true;
	    	}
	    	if(i != 0 && a[i] - a[i - 1] != 0)
	    	{
	    		all1 = false;
	    	}
	    }
	    if(near)
	    {
	    	cout << "0\n";
	    	continue;
	    }
	    if(all1)
	    {
	    	cout << min(v + u, 2 * v) << '\n';
	    	continue;
	    }
	    cout << min(u, v) << '\n';
    }
}