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
    	int n, p, k, x, y;
    	cin >> n >> p >> k;
    	--p;
    	string s;
    	cin >> s;
    	cin >> x >> y;
    	vector<set<int> > mass(k);
    	for(int i = 0; i < n; i++)
    	{
    		if(s[i] == '1')
    		{
    			mass[i % k].insert(i);
    		}
    	}
    	long long ansmin = 1000000000000ll;
    	for(int i = 0; i < n - p; i++)
    	{
    		long long ans = (long long)i * y;
    		int cell_first = i + p;
    		int k_now = (i + p) % k;
    		auto it = mass[k_now].begin();
    		while(it != mass[k_now].end() && (*it) < cell_first)
    		{
    			mass[k_now].erase(it);
    			it = mass[k_now].begin();
    		}
    		int need = (n - cell_first - 1) / k + 1;
    		ans += (long long)x * (need - (int)mass[k_now].size());
    		ansmin = min(ansmin, ans);
    	}
    	cout << ansmin << endl;
    }
}