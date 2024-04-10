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
    	if((int)s.size() % 2 == 1 || s[0] == ')' || s[s.size() - 1] == '(')
    	{
    		cout << "No\n";
    	}
    	else
    	{
    		cout << "Yes\n";
    	}
    }
}