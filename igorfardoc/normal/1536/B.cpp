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
    	string s;
    	cin >> s;
    	vector<string> now;
    	for(int i = 0; i < 26; i++)
    	{
    		string adding = "";
    		adding += (char)('a' + i);
    		now.push_back(adding);
    	}
    	for(int i = 0; i < 26; i++)
    	{
    		for(int j = 0; j < 26; j++)
			{
				string adding = "";
				adding += (char)('a' + j);
				now.push_back(now[i] + adding);
			}
    	}
    	int sz = now.size();
    	for(int i = 26; i < sz; i++)
    	{
    		for(int j = 0; j < 26; j++)
			{
				string adding = "";
				adding += (char)('a' + j);
				now.push_back(now[i] + adding);
			}
    	}
    	set<string> set1;
    	for(int i = 0; i < n; i++)
    	{
    		string s1 = "";
    		for(int j = i; j < min(n, i + 3); j++)
    		{
    			s1 += s[j];
    			set1.insert(s1);
    		}
    	}
    	for(int i = 0; i < now.size(); i++)
    	{
    		if(set1.find(now[i]) == set1.end())
    		{
    			cout << now[i] << '\n';
    			break;
    		}
    	}
    }
}