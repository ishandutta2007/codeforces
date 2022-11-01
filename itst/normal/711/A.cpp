#include<bits/stdc++.h>
using namespace std;
char s[1001][5];
int main()
{
	std::ios::sync_with_stdio(false);
	int n , f = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> s[i][0] >> s[i][1] >> s[i][2] >> s[i][3] >> s[i][4];
		if(s[i][0] == 'O' && s[i][1] == 'O' && !f)
		{
			s[i][0] = s[i][1] = '+';
			cout << "YES" << endl;
			f = 1;
		}
		else
			if(s[i][3] == 'O' && s[i][4] == 'O' && !f)
			{
				s[i][3] = s[i][4] = '+';
				cout << "YES" << endl;
				f = 1;
			}
	}
	if(!f)	cout << "NO";
	else
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < 5 ; j++)
				cout << s[i][j];
			cout << endl;
		}
	return 0;
}