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
    	int n;
    	cin >> n;
    	vector<vector<int> > d(n + 1);
    	for(int i = 0; i < n; i++)
    	{
    		int a;
    		cin >> a;
    		d[a].push_back(i);
    	}
    	bool ok = false;
    	for(int i = 0; i < n + 1; i++)
    	{
    		if(d[i].size() == 1)
    		{
    			cout << d[i][0] + 1 << endl;
    			ok = true;
    			break;
    		}
    	}
    	if(!ok)
    	{
    		cout << -1 << endl;
    	}
    }
}