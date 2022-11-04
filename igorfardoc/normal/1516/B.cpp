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
    	int now = 0;
    	int need = 0;
    	int am = 1;
    	bool ok = false;
    	for(int i = 0; i < n - 1; i++)
    	{
    		need ^= a[i];
    		now = 0;
    		am = 1;
    		for(int j = i + 1; j < n; j++)
    		{
    			now ^= a[j];
    			if(now == need)
    			{
    				ok = (j == n - 1);
    				++am;
    				now = 0;
    			}
    		}
    		if(ok || (now == 0 && am > 1))
    		{
    			ok = true;
    			break;
    		}
    	}
    	if(ok || (now == 0 && am > 1))
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}