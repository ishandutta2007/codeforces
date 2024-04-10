#include<bits/stdc++.h>
using namespace std;
string vis[1001];
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	int dir = 0;
	while(cin >> s)
	{
		int f = 0;
		string s1;
		if(s[0] == '{')	s1 = string(s , 1 , s.size() - 2);
		else	s1 = string(s , 0 , s.size() - 1);
		for(int i = 0 ; !f && i < dir ; i++)
			if(vis[i] == s1)	f = 1;
		if(!f && s1.size())	vis[dir++] = s1;
		if(s[s.size() - 1] == '}')	break;
	}
	cout << dir;
	return 0;
}