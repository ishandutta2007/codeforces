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
    	int n, x;
    	cin >> n >> x;
    	vector<int> a(n);
    	vector<int> a1(n + 1);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		a1[i] = a[i];
    	}
    	a1[n] = x;
    	sort(a1.begin(), a1.end());
    	int ansmin = 1000000000;
    	for(int i = 0; i <= n; i++)
    	{
    		vector<int> anew;
    		for(int j = 0; j <= n; j++)
    		{
    			if(j != i)
    			{
    				anew.push_back(a1[j]);
    			}
    		}
    		int ans = 0;
    		bool ok = true;
    		int x2 = x;
    		vector<int> a2 = a;
    		for(int j = 0; j < n; j++)
    		{
    			if(a2[j] == anew[j])
    			{
    				continue;
    			}
    			if(x2 == anew[j] && x2 < a2[j])
    			{
    				int temp = x2;
    				x2 = a2[j];
    				a2[j] = temp;
    				++ans;
    				continue;
    			}
    			bool ok1 = false;
				for(int k = j + 1; k < n; k++)
    			{
    				if(a2[k] == anew[j] && a2[k] > x2 && a2[k] < a2[j])
    				{
    					a2[k] = x2;
    					x2 = a2[j];
    					a2[j] = anew[j];
    					ok1 = true;
    					ans += 2;
    					break;
    				}
    			}
    			if(!ok1)
    			{
    				ok = false;
    				break;
    			}
    		}
    		if(ok)
    		{
    			ansmin = min(ansmin, ans);
    		}
    	}
    	if(ansmin == 1000000000)
    	{
    		cout << -1 << endl;
    	}
    	else
    	{
    		cout << ansmin << endl;
    	}
    }
}