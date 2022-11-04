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
    	int n, a, b;
    	cin >> n >> a >> b;
    	string s;
    	cin >> s;
    	int res = n * a;
    	if(b >= 0)
    	{
    		res += n * b;
    	}
    	else
    	{
    		int am = 1;
    		for(int i = 1; i < n; i++)
    		{
    			if(s[i] != s[i - 1])
    			{
    				++am;
    			}
    		}
			res += (am / 2 + 1) * b;
    	}
    	cout << res << '\n';
    }
}