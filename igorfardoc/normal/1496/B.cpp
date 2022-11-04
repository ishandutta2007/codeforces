#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



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
    	int n, k;
    	cin >> n >> k;
    	vector<int> a;
    	set<int> s;
    	for(int i = 0; i < n; i++)
    	{
    		int b;
    		cin >> b;
    		s.insert(b);
    	}
    	for(auto it = s.begin(); it != s.end(); ++it)
    	{
    		a.push_back(*it);
    	}
    	n = a.size();
    	int max1 = a[a.size() - 1];
    	int mex1 = -1;
    	for(int i = 0; i < n; i++)
    	{
    		if(a[i] != i)
    		{
    			mex1 = i;
    			break;
    		}
    	}
    	if(mex1 == -1)
    	{
    		cout << n + k << '\n';
    	}
    	else
    	{
    		if(k == 0)
    		{
    			cout << n << '\n';
    		}
    		else
    		{
    			int now = (max1 + mex1 - 1) / 2 + 1;
    			if(s.find(now) == s.end())
    			{
    				cout << n + 1 << '\n';
    			}
    			else
    			{
    				cout << n << '\n';
    			}
    		}
    	}
    }
}