#include<bits/stdc++.h>
using namespace std;
map <string , string> m;
int main()
{
	int n , M;
	for(cin >> n >> M ; M ; M--)
	{
		string s1 , s2;
		cin >> s1 >> s2;
		if(s1.size() > s2.size())	m.insert(make_pair(s1 , s2));
	}
	while(n)
	{
		string s;
		cin >> s;
		map <string , string> :: iterator i = m.find(s);
		if(i != m.end())	cout << i -> second << " ";
		else	cout << s << " ";
		n--;
	}
	return 0;
}