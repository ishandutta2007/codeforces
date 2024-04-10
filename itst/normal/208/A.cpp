#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int i = 0 , f = 0;
	while(string(s , i , 3) == "WUB")	i += 3;
	for( ; i < s.size(); i++)
		if(s.size() - i < 3 || string(s , i , 3) != "WUB")
		{
			cout << s[i];
			f = 1;
		}
		else
		{
			if(f)
			{
				f = 0;
				cout << " ";
			}
			i += 2;
		}
	return 0;
}