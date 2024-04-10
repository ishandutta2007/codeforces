#include<bits/stdc++.h>
#define INF 1500000000
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
    	vector<int> cond(n, INF);
    	vector<pair<int, int>> h(k);
    	for(int i = 0; i < k; i++)
    	{
    		cin >> h[i].first;
    	}
    	for(int i = 0; i < k; i++)
    	{
    		cin >> h[i].second;
    		cond[h[i].first - 1] = h[i].second;
    	}
    	int now = INF;
    	vector<int> res(n, INF);
    	for(int i = 0; i < n; i++)
    	{
    		++now;
    		now = min(now, cond[i]);
    		res[i] = min(res[i], now);
    	}
    	now = INF;
    	for(int i = n - 1; i >= 0; i--)
    	{
    		++now;
    		now = min(now, cond[i]);
    		res[i] = min(res[i], now);
    	}
    	for(int i = 0; i < n; i++)
    	{
    		cout << res[i] << ' ';
    	}
    	cout << '\n';
    }
}