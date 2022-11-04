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
    	vector<int> am(26);
    	cin >> s;
    	for(int i = 0; i < s.size(); i++)
    	{
    		++am[s[i] - 'a'];
    	}
    	int am1 = 0;
    	int am2 = 0;
    	for(int i = 0; i < 26; i++)
    	{
    		if(am[i] == 1)
    		{
    			++am1;
    		}
    		else if(am[i] >= 2)
    		{
    			++am2;
    		}
    	}
    	cout << am2 + am1 / 2 << '\n';
    }
}