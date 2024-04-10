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
    	string s;
    	cin >> s;
    	int n = s.size();
    	int l = -1;
    	int r = -1;
    	for(int i = 0; i < n; i++)
    	{
    		if(s[i] == 'a')
    		{
    			l = i;
    			r = i;
    			break;
    		}
    	}
    	if(l == -1)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	bool ok = true;
    	for(int i = 0; i < n - 1; i++)
    	{
    		if(l != 0 && s[l - 1] == (char)(i + 'b'))
    		{
    			--l;
    			continue;
    		}
    		if(r != n - 1 && s[r + 1] == (char)(i + 'b'))
    		{
    			++r;
    			continue;
    		}
    		ok = false;
    		break;
    	}
    	if(ok)
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}