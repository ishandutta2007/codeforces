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
    	int n, m;
    	cin >> n >> m;
    	vector<string> a(n);
    	bool ok = true;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		for(int j = 0; j < m; j++)
    		{
    			if(((i + j) % 2 == 0 && a[i][j] == 'R') || ((i + j) % 2 == 1 && a[i][j] == 'W'))
    			{
    				ok = false;
    			}
    		}
    	}
    	bool ok1 = false;
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < m; j++)
    		{
    			char need = '.';
    			if(ok)
    			{
    				if((i + j) % 2 == 0)
    				{
    					need = 'W';
    				}
    				else
    				{
    					need = 'R';
    				}
    			}
    			else
    			{
    				if((i + j) % 2 == 0)
    				{
    					need = 'R';
    				}
    				else
    				{
    					need = 'W';
    				}
    			}
    			if(a[i][j] == '.')
    			{	
    				a[i][j] = need;
    			}
    			if(a[i][j] == need)
    			{
    				continue;
    			}
    			cout << "NO\n";
    			ok1 = true;
    			break;
    		}
    		if(ok1)
    		{
    			break;
    		}
    	}
    	if(!ok1)
    	{
    		cout << "YES\n";
    		for(int i = 0; i < n; i++)
    		{
    			cout << a[i] << '\n';
    		}
    	}
    }
}