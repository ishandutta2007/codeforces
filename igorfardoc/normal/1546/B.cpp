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
    	vector<vector<int>> am(m, vector<int>(26, 0));
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < m; j++)
    		{
    			char c;
    			cin >> c;
    			am[j][c - 'a']++;
    		}
    	}
    	for(int i = 0; i < n - 1; i++)
    	{
    		for(int j = 0; j < m; j++)
    		{
    			char c;
    			cin >> c;
    			am[j][c - 'a']--;
    		}
    	}
    	for(int i = 0; i < m; i++)
    	{
    		for(int j = 0; j < 26; j++)
    		{
    			if(am[i][j] == 1)
    			{
    				cout << (char)('a' + j);
    				break;
    			}
    		}
    	}
    	cout << endl;
    }
}