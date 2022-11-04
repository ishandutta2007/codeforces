#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
    	string now;
    	cin >> now;
    	string res = "";
    	while(now.size() > 0)
    	{
    		int n = now.size();
    		vector<int > am(26);
    		for(int i = 0; i < n; i++)
    		{
    			am[now[i] - 'a']++;
    		}
    		int id1 = 0;
    		vector<int> am1(26, 0);
    		for(int i = 0; i < n; i++)
    		{
    			if(now[i] > now[id1])
    			{
    				id1 = i;
    			}
    			++am1[now[i] - 'a'];
    			if(am1[now[i] - 'a'] == am[now[i] - 'a'])
    			{
    				break;
    			}
    		}
    		res += now[id1];
    		string next = "";
    		for(int i = id1 + 1; i < n; i++)
    		{
    			if(now[id1] == now[i])
    			{
    				continue;
    			}
    			next += now[i];
    		}
    		now = next;
    	}
    	cout << res << '\n';
    }
}