#include<bits/stdc++.h>
#define MAX 300000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

mt19937 rnd(42);



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, q;
    cin >> n >> q;
    vi a(n);
    vvi am(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	--a[i];
    	am[a[i]].push_back(i);
    }


    for(int o =0 ; o < q; o++)
    {
    	int l, r;
    	cin >> l >> r;
    	l--;
    	r--;
    	int max1 = 0;
    	uniform_int_distribution<int> rng(l, r);
    	for(int c = 0; c < 40; c++)
    	{
    		int here = rng(rnd);
    		int value = a[here];
    		int amount = upper_bound(am[value].begin(), am[value].end(), r) - lower_bound(am[value].begin(), am[value].end(), l);
    		max1 = max(max1, amount);
    	}
    	int l1 = 0;
    	int r1 = MAX;
    	while(r1 - l1 > 1)
    	{
    		int mid = (l1 + r1) / 2;
    		int can = mid;
    		int heremax = max1;
    		int len = r - l + 1;
    		int heremin = len - max1;
    		if(mid >= len || heremin + 1 >= heremax)
    		{
    			r1 = mid;
    			continue;
    		}
    		int take = min(mid - 1, heremin);
    		can -= take;
    		heremin -= take;
    		heremax -= take * 2;
    		heremax -= (can - 1);
    		can = 1;
    		if(heremin + 1 >= heremax || heremax <= 0)
    		{
    			r1 = mid;
    			continue;
    		}
    		l1 = mid;
    	}
    	cout << r1 << '\n';
    }
}