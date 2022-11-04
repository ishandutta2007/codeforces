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
    	int n, k;
    	cin >> n >> k;
    	vector<pair<int, int> > mass(n);
    	for(int i = 0; i < n; i++)
    	{
    		int a;
    		cin >> a;
    		mass[i] = {a, a + k - 1};
    		if(i == 0 || i == n - 1)
    		{
    			mass[i] = {a, a};
    		}
    	}
    	bool ok = true;
    	for(int i = 0; i < n; i++)
    	{
    		if(mass[i].second < mass[i].first || mass[i].second < 0)
    		{
    			cout << "No\n";
    			ok = false;
    			break;
    		}
    		mass[i].first = max(0, mass[i].first);
    		if(i == n - 1)
    		{
    			break;
    		}
    		mass[i + 1].second = min(mass[i + 1].second, mass[i].second + k - 1);
    		mass[i + 1].first = max(mass[i + 1].first, mass[i].first - k + 1);
    	}
    	if(ok)
    	{
    		cout << "Yes\n";
    	}
    }
}