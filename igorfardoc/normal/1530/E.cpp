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
    	string s;
    	cin >> s;
    	int n = s.size();
    	int amount = 0;
    	vector<int> am(26);
    	int min1 = -1;
    	int minid = 0;
    	int id1 = -1;
    	int other = -1;
    	int other1 = -1;
    	for(int i = 0; i < n; i++)
    	{
    		am[s[i] - 'a']++;
    	}
    	for(int i = 0; i < 26; i++)
    	{
    		if(am[i] != 0)
    		{
    			if(id1 == -1 && am[i] == 1)
    			{
    				id1 = i;
    			}
    			amount++;
    			if(min1 == -1)
    			{
    				min1 = am[i];
    				minid = i;
    			}
    			else if(other == -1)
    			{
    				other = i;
    			} else if(other1 == -1)
    			{
    				other1 = i;
    			}
    		}
    	}
    	if(id1 != -1)
    	{
    		cout << (char)(id1 + 'a');
    		string s1 = "";
    		--am[id1];
    		for(int i = 0; i < 26; i++)
    		{
    			for(int j = 0; j < am[i]; j++)
    			{
    				s1 += (char)(i + 'a');
    			}
    		}
    		sort(s1.begin(), s1.end());
    		cout << s1 << '\n';
    		continue;
    	}
    	if(amount == 1 || n <= 3)
    	{
    		sort(s.begin(), s.end());
    		cout << s << '\n';
    		continue;
    	}
    	if((n - 2) / 2 >= min1 - 2)
    	{
    		cout << (char)(minid + 'a') << (char)(minid + 'a');
    		am[minid] -= 2;
    		int now = minid + 1;
    		while(now < 26)
    		{
    			if(am[now] == 0)
    			{
    				++now;
    				continue;
    			}
    			cout << (char)(now + 'a');
    			--am[now];
    			if(am[minid] == 0)
    			{
    				continue;
    			}
    			cout << (char)(minid + 'a');
    			--am[minid];
    		}
    		cout << '\n';
    		continue;
    	}
    	if(amount == 2)
    	{
    		cout << (char)(minid + 'a');
    		am[minid]--;
    		for(int i = 0; i < am[other]; i++)
    		{
    			cout << (char)(other + 'a');
    		}
    		for(int i = 0; i < am[minid]; i++)
    		{
    			cout << (char)(minid + 'a');
    		}
    		cout << '\n';
    		continue;
    	}
    	cout << (char)(minid + 'a');
    	am[minid]--;
    	cout << (char)(other + 'a');
		am[other]--;
		for(int i = 0; i < am[minid]; i++)
		{
			cout << (char)(minid + 'a');
		}
		cout << (char)(other1 + 'a');
		am[other1]--;
		for(int i = other; i < 26; i++)
		{
			for(int j = 0; j < am[i]; j++)
			{
				cout << (char)(i + 'a');
			}
		}
		cout << '\n';
    }
}