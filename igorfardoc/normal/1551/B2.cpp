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
    	vector<int> a(n);
    	vector<int> am(n + 1);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		am[a[i]]++;
    	}
    	ll amount = 0;
    	for(int i = 0; i <= n; i++)
    	{
    		amount += min(am[i], k);
    	}
    	amount = amount / k * k;
    	vector<vector<int>> am1(n + 1);
    	int now = 0;
    	int all1 = 0;
    	for(int i = 0; i <= n; i++)
    	{
    		int here = min(am[i], k);
    		for(int j = 0; j < here; j++)
    		{
    			if(all1 == amount)
    			{
    				break;
    			}
    			am1[i].push_back(now);
    			now = (now + 1) % k;
    			++all1;
    		}
    	}
    	for(int i = 0; i < n; i++)
    	{
    		if(am1[a[i]].empty())
    		{
    			cout << "0 ";
    		}
    		else
    		{
    			cout << am1[a[i]][am1[a[i]].size() - 1] + 1 << ' ';
    			am1[a[i]].pop_back();
    		}
    	}
    	cout << '\n';
    }
}