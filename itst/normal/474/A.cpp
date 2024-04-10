#include<bits/stdc++.h>
using namespace std;
char ex[3][11] = {"qwertyuiop" , "asdfghjkl;" , "zxcvbnm,./"};
int main()
{
	std::ios::sync_with_stdio(false);
	char c;
	string s;
	cin >> c >> s;
	for(int i = 0 ; i < s.size() ; i++)
	{
		int f = 1;
		for(int j = 0 ; j < 3 && f ; j++)
			for(int k = 0 ; f && k < 10 ; k++)
				if(ex[j][k] == s[i])
				{
					if(c == 'R')	cout << ex[j][k - 1];
					else	cout << ex[j][k + 1];
					f = 1;
				}
	}
	return 0;
}