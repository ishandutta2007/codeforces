#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> res;

void printres()
{
	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	cout << '\n';
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
    		a[i]--;
    	}
    	vector<int> am(n, 0);
    	res.assign(n, 0);
    	for(int i = 0; i < n; i++)
    	{
    		am[a[i]]++;
    	}
    	if(am[0] == 0)
    	{
    		printres();
    		continue;
    	}
    	res[n - 1] = 1;
    	bool ok = true;
    	for(int i = 0; i < n; i++)
    	{
    		if(am[i] == 0)
    		{
    			ok = false;
    			break;
    		}
    	}
    	if(ok)
    	{
    		res[0] = 1;
    	}
    	int l = -1;
    	int r = n;
    	for(int i = n - 2; i >= 1; i--)
    	{
    		int val1 = n - i - 2;
    		if(am[val1] != 1)
    		{
    			break;
    		}
    		if(a[l + 1] == val1)
    		{
    			++l;
    		}
    		else if(a[r - 1] == val1)
    		{
    			--r;
    		}
    		else
    		{
    			break;
    		}
    		if(am[val1 + 1] == 0)
    		{
    			break;
    		}
    		res[i] = 1;
    	}
    	printres();
    }
}