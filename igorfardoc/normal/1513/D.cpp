#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int n, p;
vi a;
vector<bool> used;


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
    	cin >> n >> p;
    	a.resize(n);
    	map<int, vector<int>> d;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		d[a[i]].push_back(i);
    	}
    	used.assign(n, false);
    	int amount = 0;
    	ll res = 0;
    	for(const auto& el : d)
    	{
    		int val = el.first;
    		if(val >= p)
    		{
    			continue;
    		}
    		for(const auto& id : el.second)
    		{
    			if(used[id])
    			{
    				continue;
    			}
    			int r = id;
    			while(true)
    			{
    				if(r == n - 1 || a[r + 1] % val != 0 || used[r + 1])
    				{
    					break;
    				}
    				++r;
    			}
    			int l = id;
    			while(true)
    			{
    				if(l == 0 || a[l - 1] % val != 0 || used[l - 1])
    				{
    					break;
    				}
    				--l;
    			}
    			res += (ll)val * (r - l);
    			amount += r - l;
    			used[id] = true;
    			for(int i = l + 1; i < r; i++)
    			{
    				used[i] = true;
    			}
    		}
    	}
    	res += (ll)(n - 1 - amount) * p;
    	cout << res << '\n';
    }
}