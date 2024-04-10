#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int can(vector<int> & b, vector<int> & a, int x)
{
	vector<bool> used(2 * n, false);
	for(int i = 0; i < n; i++)
	{
		used[b[i]] = true;
	}
	int now = 2 * n - 1;
	for(; now >= 0; now--)
	{
		if(!used[now])
		{
			break;
		}
	}
	for(int i = x - 1; i >= 0; i--)
	{
		if(b[i] > now)
		{
			return 2;
		}
		used[now] = true;
		for(; now >= 0; now--)
		{
			if(!used[now])
			{
				break;
			}
		}
	}
	now = 0;
	for(; now < 2 * n; now++)
	{
		if(!used[now])
		{
			break;
		}
	}
	for(int i = x; i < n; i++)
	{
		if(b[i] < now)
		{
			return 1;
		}
		used[now] = true;
		for(; now < 2 * n; now++)
		{
			if(!used[now])
			{
				break;
			}
		}
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
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n;
    	vector<int> b(n);
    	vector<int> a(2 * n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> b[i];
    		--b[i];
    	}
    	for(int i = 0; i < 2 * n; i++)
    	{
    		a[i] = i;
    	}
    	int l = -1;
    	int r = n;
    	while(r - l > 1)
    	{
    		int mid = (l + r) / 2;
    		int val = can(b, a, mid);
    		if(val == 0)
    		{
    			r = mid;
    		}
    		else if(val == 2)
    		{
    			r = mid;
    		}
    		else
    		{
    			l = mid;
    		}
    	}
    	if(can(b, a, r) != 0)
    	{
    		--r;
    	}
    	int l1 = 0;
    	int r1 = n + 1;
    	while(r1 - l1 > 1)
    	{
    		int mid = (l1 + r1) / 2;
    		int val = can(b, a, mid);
    		if(val == 0)
    		{
    			l1 = mid;
    		}
    		else if(val == 2)
    		{
    			r1 = mid;
    		}
    		else
    		{
    			l1 = mid;
    		}
    	}
    	if(can(b, a, l1) != 0)
    	{
    		l1++;
    	}
    	cout << l1 - r + 1 << '\n';
    }
}