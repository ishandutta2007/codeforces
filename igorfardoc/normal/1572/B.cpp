#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int n;
int sum;
vector<int> a;
vector<int> ans;

bool rec(int k)
{
	int a1 = -1;
	int a2 = -1;
	for(int i = k; i >= 0; i--)
	{
		if(a[i])
		{
			if(a2 == -1)
			{
				a2 = i;
			}
			else
			{
				a1 = i;
			}
		}
		if(a1 != -1 && a2 != -1)
		{
			break;
		}
	}
	if(a1 == -1 && a2 == -1)
	{
		return true;
	}
	if((a2 - a1) % 2 == 0)
	{
		for(int i = a1; i < a2 - 1; i += 2)
		{
			ans.push_back(i);
		}
		for(int i = a2 - 4; i >= a1; i -= 2)
		{
			ans.push_back(i);
		}
		a[a1] = 0;
		a[a2] = 0;
		return rec(a1);
	}
	else if(a2 < k)
	{
		while(a2 - a1 > 2)
		{
			ans.push_back(a2 - 2);
			ans.push_back(a2 - 1);
			a2 -= 2;
		}
		ans.push_back(a1);
		a[a1] = 0;
		return rec(a1);
	}
	else if(a1 != 0 && a[a1 - 1] == 0)
	{
		int bef = a1;
		while(a2 - a1 > 2)
		{
			ans.push_back(a1);
			ans.push_back(a1 - 1);
			a1 += 2;
		}
		ans.push_back(a2 - 2);
		return rec(bef - 1);
	}
	else
	{
		if(a1 == 0)
		{
			return false;
		}
		if(!rec(a1 - 1))
		{
			return false;
		}
		int bef = a1;
		while(a2 - a1 > 2)
		{
			ans.push_back(a1);
			ans.push_back(a1 - 1);
			a1 += 2;
		}
		ans.push_back(a2 - 2);
		return true;
	}
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
    	a.resize(n);
    	sum = 0;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		sum += a[i];
    	}
    	if(sum % 2 == 1)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	ans.resize(0);
    	if(rec(n - 1))
    	{
    		cout << "YES\n";
    		cout << ans.size() << '\n';
    		for(int i = 0; i < ans.size(); i++)
    		{	
    			cout << ans[i] + 1 << ' ';
    		}
    		cout << '\n';
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}