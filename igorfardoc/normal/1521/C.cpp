#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int q(int t, int i, int j, int x)
{
	cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
	int val;
	cin >> val;
	return val;
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
    	int pos = n - 1;
    	for(int i = 0; i < n / 2; i++)
    	{
    		int res = q(1, 2 * i, 2 * i + 1, n - 1);
    		if(res == n)
    		{
    			pos = 2 * i + 1;
    			break;
    		}
    		else if(res == n - 1)
    		{
    			if(q(1, 2 * i + 1, 2 * i, n - 1) == n)
    			{
    				pos = 2 * i;
    				break;
    			}
    		}
    	}
    	vector<int> a(n);
    	a[pos] = n;
    	for(int i = 0; i < n; i++)
    	{
    		if(i == pos)
    		{	
    			continue;
    		}
    		a[i] = q(2, i, pos, 1);
    	}
    	cout << "! ";
    	for(int i = 0; i < n; i++)
    	{
    		cout << a[i] << ' ';
    	}
    	cout << endl;
    }
}