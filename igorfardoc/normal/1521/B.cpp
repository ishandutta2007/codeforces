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
    	int min1 = 1000000001;
    	int minid = -1;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		if(a[i] < min1)
    		{
    			min1 = a[i];
    			minid = i;
    		}
    	}
    	vector<pair<pair<int, int>, pair<int, int> > > op;
    	if(minid != 0)
    	{
    		op.push_back({{0, minid}, {min1, min1}});
    	}
    	a[0] = min1;
    	for(int i = 1; i < n; i++)
    	{
    		op.push_back({{0, i}, {min1, a[i - 1] + 1}});
    		a[i] = a[i - 1] + 1;
    	}
    	cout << op.size() << '\n';
    	for(int i = 0; i < op.size(); i++)
    	{
    		cout << op[i].first.first + 1 << ' ' << op[i].first.second + 1 << ' ' <<
    		op[i].second.first << ' ' << op[i].second.second << '\n';
    	}
    }
}