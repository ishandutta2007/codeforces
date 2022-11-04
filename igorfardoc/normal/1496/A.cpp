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
    	string s;
    	cin >> s;
    	if(n % 2 == 0 && n / 2 == k)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	bool ok = true;
    	for(int i = 0; i < k; i++)
    	{
    		if(s[i] != s[n - i - 1])
    		{
    			cout << "NO\n";
    			ok = false;
    			break;
    		}
    	}
    	if(ok)
    	{
    		cout << "YES\n";
    	}
    }
}