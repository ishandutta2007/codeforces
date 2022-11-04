#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> res, a;
vector<int> pref;

void solve(int last, int l, int r)
{
	if(last == -1)
	{
		return;
	}
	int now = pref[last];
	res[l] = a[now];
	int len = last - now;
	for(int i = r - len + 1; i <= r; i++)
	{
		res[i] = a[now + 1 + i - (r - len + 1)];
	}
	solve(now - 1, l + 1, r - len);
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
    	a.resize(n);
    	res.resize(n);
    	pref.resize(n);
    	pref[0] = 0;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		--a[i];
    		if(i == 0)
    		{
    			continue;
    		}
    		if(a[i] < a[pref[i - 1]])
    		{
    			pref[i] = i;
    		}
    		else
    		{
    			pref[i] = pref[i - 1];
    		}
    	}
    	solve(n - 1, 0, n - 1);
    	for(int i = 0; i < n; i++)
    	{
    		cout << res[i] + 1 << ' ';
    	}
    	cout << '\n';
    }
}