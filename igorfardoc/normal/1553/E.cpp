#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a;
int n, m;

bool check(int per)
{
	vector<int> b(n);
	for(int i = 0; i < per; i++)
	{
		b[i] = n - per + i;
	}
	for(int i = per; i < n; i++)
	{
		b[i] = i - per;
	}
	vector<int> where(n);
	for(int i = 0; i < n; i++)
	{
		where[b[i]] = i;
	}
	int am = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(a[i] == b[i])
		{
			continue;
		}
		int here = b[i];
		++am;
		where[b[i]] = where[a[i]];
		b[i] = a[i];
		b[where[a[i]]] = here;
		where[a[i]] = i;
	}
	return am <= m;
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
    	cin >> n >> m;
    	a.resize(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		--a[i];
    	}
    	vector<int> per(n);
    	for(int i = 0; i < n; i++)
    	{
    		++per[(i - a[i] + n) % n];
    	}
    	vector<int> ans;
    	for(int i = 0; i < n; i++)
    	{
    		if(per[i] * 3 >= n)
    		{
    			if(check(i))
    			{
    				ans.push_back(i);
    			}
    		}
    	}
    	cout << ans.size() << ' ';
    	for(auto el : ans)
    	{
    		cout << el << ' ';
    	}
    	cout << '\n';
    }
}