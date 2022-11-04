#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<int>& a, int l, int r)
{
	if(r - l + 1 <= 2)
	{
		return true;
	}
	for(int i = l; i <= r; i++)
	{
		for(int j = i + 1; j <= r; j++)
		{
			for(int k = j + 1; k <= r; k++)
			{
				if(a[i] <= a[j] && a[j] <= a[k])
				{
					return false;
				}
				if(a[i] >= a[j] && a[j] >= a[k])
				{
					return false;
				}
			}
		}
	}
	return true;
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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	int res = 0;
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = i; j < min(i + 4, n); j++)
    		{
    			if(check(a, i, j))
    			{
    				++res;
    			}
    		}
    	}
    	cout << res << '\n';
    }
}