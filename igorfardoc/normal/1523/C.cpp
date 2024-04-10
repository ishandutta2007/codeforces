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
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	vector<int> now = {1};
    	cout << "1\n";
    	for(int i = 1; i < n; i++)
    	{
    		if(a[i] == 1)
    		{
    			now.push_back(1);
    		}
    		else
    		{
    			while(now[now.size() - 1] != a[i] - 1)
    			{
    				now.pop_back();
    			}
    			now.pop_back();
    			now.push_back(a[i]);
    		}
    		for(int j = 0; j < now.size(); j++)
    		{
    			cout << now[j];
    			if(j != now.size() - 1)
    			{
    				cout << '.';
    			}
    		}
    		cout << '\n';
    	}
    }
}