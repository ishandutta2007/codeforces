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
    	int n;
    	cin >> n;
    	vector<int> a(n), b(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	for(int i = 0; i < n; i++)
    	{
    		cin >> b[i];
    	}
    	vector<int> a1, a2;
    	for(int i = 0; i < n; i++)
    	{
    		if(a[i] > b[i])
    		{
    			for(int j = 0; j < a[i] - b[i]; j++)
    			{
    				a1.push_back(i);
    			}
    		}
    		else
    		{
    			for(int j = 0; j < b[i] - a[i]; j++)
    			{
    				a2.push_back(i);
    			}
    		}
    	}
    	if(a1.size() != a2.size())
    	{
    		cout << "-1\n";
    		continue;
    	}
    	cout << a1.size() << '\n';
    	for(int i = 0; i < a1.size(); i++)
    	{
    		cout << a1[i] + 1 << ' ' << a2[i] + 1 << '\n';
    	}
    }
}