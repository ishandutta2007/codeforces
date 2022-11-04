#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getnext(ll pos, ll x, int t)
{
	if(t == 1)
	{
		ll d = (x - 1) / 100000 + 1;
		return pos + d;
	}
	if(pos == 0)
	{
		return 0;
	}
	return (x * pos - 1) / 100000 + 1;
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
    int n, m;
    cin >> n >> m;
    vector<int> res(m + 1, -1);
    res[0] = 0;
    for(int i = 0; i < n; i++)
    {
    	int t;
    	ll x, y;
    	cin >> t >> x >> y;
    	vector<int> newres = res;
    	for(int j = m; j >= 0; j--)
    	{
    		if(newres[j] == -1)
    		{
    			continue;
    		}
    		ll pos = getnext(j, x, t);
    		for(int k = 0; k < y; k++)
    		{
    			if(pos > m || res[pos] != -1)
    			{
    				break;
    			}
    			newres[pos] = i + 1;
    			pos = getnext(pos, x, t);
    		}
    	}
    	res = newres;
    }
    for(int i = 0; i < m; i++)
    {
    	cout << res[i + 1] << ' ';
    }
}