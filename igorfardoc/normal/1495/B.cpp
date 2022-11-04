#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<pair<int, int> > b;

int sz(int a)
{
	if(a < 0 || a >= b.size())
	{
		return b[a].second - b[a].first + 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    int prev = 0;
    bool up;
    for(int i = 1; i < n; i++)
    {
    	if(i == prev + 1)
    	{
    		up = a[i] > a[i - 1];
    		continue;
    	}
    	if(up != a[i] > a[i - 1])
    	{
    		b.push_back({prev, i - 1});
    		prev = i - 1;
    		up = a[i] > a[i - 1];
    	}
    }
    b.push_back({prev, n - 1});
    int max1 = -1;
    int k = b.size();
    for(int i = 0; i < k; i++)
    {
    	max1 = max(max1, b[i].second - b[i].first + 1);
    }
    vector<int> ids;
    for(int i = 0; i < k; i++)
    {
    	if(max1 == b[i].second - b[i].first + 1)
    	{
    		ids.push_back(i);
    	}
    }
    if(ids.size() != 2)
    {
    	cout << 0;
    	return 0;
    }
    if(ids.size() == 2)
    {
    	if(abs(ids[0] - ids[1]) != 1)
    	{
    		cout << 0;
    		return 0;
    	}
    	if(a[b[ids[0]].first] > a[b[ids[0]].second])
    	{
    		cout << 0;
    		return 0;
    	}
    	if(max1 % 2 == 1)
    	{
    		cout << 1;
    		return 0;
    	}
    	cout << 0;
    	return 0;
    }
}